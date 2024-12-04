#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>

static std::vector<int> get_substr_locations(std::string searchMe, std::string findMe){
    std::vector<int> retMe;
    
    int pos = 0;
    
    while (pos<searchMe.size()&&pos>=0){
        if(searchMe.substr(pos).find(findMe)!=std::string::npos)
            pos += searchMe.substr(pos).find(findMe);
        else break;
        
        if(pos<searchMe.size()&&pos>=0){
            retMe.push_back( pos );
            pos+=findMe.size();
        }
    }
    
    
    return retMe;
}

#endif//STRING_H

