#ifndef INPUT_FILE_H
#define INPUT_FILE_H

#include <fstream>
#include <string>
#include <vector>

static std::vector<std::string> read_input(int i){// this is for AoC, not good practice, but is easy for competition/fast typing programming.
    std::vector<std::string> retMe;
    std::string padded_str = std::to_string(i);
    if( i > 25 or i < 1 ) exit(-8);
    if( padded_str.size() == 1 ) padded_str = "0" + padded_str;
    std::fstream file("input/"+padded_str+"/input.txt");
    
    std::string line;
    while( std::getline(file,line) ){
        if(line != "") retMe.push_back(line);
    }
    return retMe;
}

#endif//INPUT_FILE_H

