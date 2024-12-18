#ifndef INPUT_FILE_H
#define INPUT_FILE_H

#include <fstream>
#include <string>
#include <vector>

static std::vector<std::string> read_input(int i){// static header functions are for AoC. Not good practice, but is easy for competition/fast typing programming.
    std::vector<std::string> retMe;
    std::string padded_str = std::to_string(i);
    if( (i > 25) or (i < 1) ){
        std::cout << "The integer '" + std::to_string(i) + "' is an invalid day number. Exiting." << std::endl;
        exit(-1);
    }
    if( padded_str.size() == 1 ) padded_str = "0" + padded_str;
    std::fstream file("input/"+padded_str+"/input.txt");
    
    if( !file.good() ){
        std::cout << "Input file \"input/"+padded_str+"/input.txt not found. Exiting." << std::endl;
        exit(-1);
    }
    
    std::string line;
    while( std::getline(file,line) ){
        if(line != "") retMe.push_back(line);
    }
    return retMe;
}

static std::vector<std::string> read_test(int i, int j){
    std::vector<std::string> retMe;
    std::string padded_str_i = std::to_string(i);
    if( i < 1 ){
        std::cout << "The integer '" + std::to_string(i) + "' is an invalid day number. Exiting." << std::endl;
        exit(-1);
    }
    if( padded_str_i.size() == 1 ) padded_str_i = "0" + padded_str_i;

    std::string padded_str_j = std::to_string(j);
    if( i < 1 ){
        std::cout << "The integer '" + std::to_string(j) + "' is an invalid test number. Exiting." << std::endl;
        exit(-1);
    }
    if( padded_str_j.size() == 1 ) padded_str_j = "0" + padded_str_j;

    std::fstream file("test/"+padded_str_i+"/test_" + padded_str_j + ".txt");
    
    if( !file.good() ){
        std::cout << "Input file \"test/"+padded_str_i+"/test_" + padded_str_j + ".txt\" not found. Exiting." << std::endl;
        exit(-1);
    }
    
    std::string line;
    while( std::getline(file,line) ){
        if(line != "") retMe.push_back(line);
    }
    return retMe;
}

#endif//INPUT_FILE_H

