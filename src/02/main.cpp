#include "../AoC.h"

bool is_safe(std::vector<int> checkMe){
    
    if(!is_strictly_monotonic(checkMe))
        return false;
    
    for(int i = 1; i < checkMe.size(); i++)
        if(std::abs(checkMe[i]-checkMe[i-1])>3)
            return false;
    
    return true;
}

int main(){
    
    std::vector<std::string> d = read_input(2);
    int total = 0;
    
    for(auto line : d){
        if( is_safe(to_int(split(line," "))) )
            total++;
    }
    
    std::cout << "Part one answer: " << total << std::endl;
    
    total = 0;
    
    for(auto line : d){
        if( is_safe(to_int(split(line," "))) )
            total++;
        else{
            for(int i = 0; i < (to_int(split(line," "))).size(); i++){
                auto v = (to_int(split(line," ")));
                v.erase(v.begin() + i);
                if(is_safe(v)){
                    total++;
                    break;
                }
            }
        }
    }
    
    std::cout << "Part two answer: " << total << std::endl;
}

