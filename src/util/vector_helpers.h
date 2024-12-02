#ifndef VECTOR_HELPERS_H
#define VECTOR_HELPERS_H

#include <string>
#include <vector>

std::vector<int> to_int(std::vector<std::string> convertMe){
    std::vector<int> retMe;
    for(auto str : convertMe){
        retMe.push_back(std::stoi(str));
    }
    return retMe;
}

#endif//VECTOR_HELPERS_H

