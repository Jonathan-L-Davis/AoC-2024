#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H

#include <string>
#include <vector>

static std::vector<std::string> split(std::string splitMe, std::string ws){// this is for AoC, not good practice, but is easy for competition/fast typing programming.
    std::vector<std::string> retMe;
    
    std::string current_str;
    for(int i = 0; i < splitMe.size(); i++){
        
        if( splitMe.size()-i < ws.size() ){
            retMe.push_back( current_str + splitMe.substr(i));
            break;
        }
        
        if( splitMe.substr(i,ws.size()) == ws ){
            i += ws.size()-1;
            if(current_str.size()>0) retMe.push_back(current_str);
            current_str = "";
            continue;
        }
        
        current_str += splitMe[i];
    }
    if(current_str.size()>0) retMe.push_back(current_str);
    return retMe;
}

#endif//STRING_SPLIT_H

