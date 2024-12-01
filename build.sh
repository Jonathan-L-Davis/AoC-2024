#!/usr/bin/bash

day_01=( "src/01/main.cpp" )
day_02=( "src/01/main.cpp" )
Compiler=""

# compiler search needs to be abstracted slightly, but oh well, works for the moment. 
# search for valid compiler. Print nothing if clang is found w/ support for c++17 since that's our ideal. Complain if g++ works, since we really only want to support clang++.
# Then fail otherwise, since we can't build for any other compiler right now. Could maybe support msvc at some point w/ git bash, but ugghh.
touch test.cpp
if [[ -z "$Compiler" && ! -z $(command -v "clang++") ]]; then
    if [[ -z $(clang++ --std=c++terriblearg -c test.cpp 2>&1 | grep c++20 ) ]] ; then # this check is compiler dependent. Clang emits correct/supported standards when given a bad one.
        echo "Installed Clang version does not support c++20"
    else
        Compiler="clang++"
    fi
elif [[ -z "$Compiler" ]] ; then
    echo "clang++ not found. Looking for g++."
fi
rm test.cpp

if [[ -z "$Compiler" && ! -z $(command -v "g++") ]] ; then
    if [[ -z $(g++ -v --help 2> /dev/null | sed -n '/^ *-std=\([^<][^ ]\+\).*/ {s//\1/p}' | grep c++20) ]] ; then # THX https://stackoverflow.com/users/616460/jason-c with https://stackoverflow.com/questions/34836775/compiler-standards-support-c11-c14-c17
        echo "Installed g++ version does not support c++20"
    else
        Compiler="g++"
        echo "Found g++, building."
    fi
elif [[ -z "$Compiler" ]] ; then
    echo "g++ not found. Giving up."
fi

if [[ -z $Compiler ]] ; then
    echo "Could not find suitable compiler"
    exit
fi


# creates the appropriate folders before object files, so that the compiler can actually put them in said folder. Some compilers won't create folders, even if specified in the output filename.
# then make object files.
# then link object files into an executable.
link_objects( ){
    compiler="$1" # should be a string for the compiler command
    objects="$2" # should be a ws separated string of object file names
    executable_name="$3" # should be a string for the exectuable name

    $compiler $objects -o $executable_name
}

compile_files( ){
    compiler="$1"
    sourcex=$2[@]
    source=("${!sourcex}")
    
    mkdir -p obj
    for file in "${source[@]}" ; do
        # can probably actually handle spaces. Will test later and remove this silly check.
        if [[ $file =~ [[:space:]]+ ]] ; then
            echo "File path: \"$file\" Contains a space and should not."
            exit 1
        fi

        object_files=()
        object_file="obj/$(echo $file | sed -e 's/\.cpp/\.o/')"
        
        path="${file%/*}"
        object_files+=( "${object_file}" )
        mkdir -p "obj/$path" # otherwise clang++/g++ complain about non-existing directory
        $compiler "$file" -c -o "${object_file}" -std=c++20
    done
    object_files_glob=""
    for object in "${object_files[@]}" ; do
        object_files_glob+="$object"
    done 
}


# start normal script execution here ( need to refactor compiler checks.)

# argument parsing goes here

# compiler checks go here

mkdir -p gen # where the executables go
mkdir -p input # where the input files go for each day.
cp input gen -r
mkdir -p output # where any file output goes to be stored for later (incase of multistage processing.)
compile_files $Compiler day_01
link_objects "$Compiler" "$object_files_glob" "gen/day_01"
compile_files $Compiler day_02
link_objects "$Compiler" "$object_files_glob" "gen/day_02"

