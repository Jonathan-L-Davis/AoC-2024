#include "../AoC.h"

int do_the_mul(std::string line, int idx){
    if(line[idx]!='(')
        return 0;
    idx++;
    
    std::string p;
    int n1,n2;
    for( int num_idx = idx; idx-num_idx<=3&&std::isdigit(line[idx]); idx++ )
        p += line[idx];
    if(p=="") return 0;
    n1 = std::stoi(p);
    
    if(line[idx]!=',')
        return 0;
    idx++;
    
    p = "";
    
    for( int num_idx = idx; idx-num_idx<=3&&std::isdigit(line[idx]); idx++ )
        p += line[idx];
    if(p=="") return 0;
    n2 = std::stoi(p);
    
    if(line[idx]!=')')
        return 0;
    return n1*n2;
}

struct enabler{ bool enabled = true; int idx = 0; };

int main(){
    
    
    auto d = read_input(3);
    //auto d = read_test(3,3);
    int64_t total = 0;
    for(auto line : d){
        
        auto line_idx = get_substr_locations(line,"mul");
        for(auto idx : line_idx){
            total += do_the_mul(line,idx+3);
        }
        
    }
    
    std::cout << "Part one answer: " << total << std::endl;
    total = 0;
    
    for(auto line : d){
        
        auto mul_idx = get_substr_locations(line,"mul");
        
        auto dont_idx = get_substr_locations(line,"don't()");
        auto does_idx = get_substr_locations(line,"do()");
        
        std::vector<enabler> enable = {{true,0}};
        
        //assuming they cannot share idx's (cuz they can't)
        while( dont_idx.size() > 0 || does_idx.size() > 0 ){
            if( dont_idx.size()>0 && does_idx.size()>0 ){
                if( dont_idx[0] < does_idx[0] ){
                    enable.push_back({false,dont_idx[0]});
                    dont_idx.erase(dont_idx.begin());
                }
                else{
                    enable.push_back({true,does_idx[0]});
                    does_idx.erase(does_idx.begin());
                }
            }else if(dont_idx.size()>0){
                enable.push_back({false,dont_idx[0]});
                break;
            }else if(does_idx.size()>0){
                enable.push_back({true,does_idx[0]});
                break;
            }
        }
        
        for(auto idx : mul_idx){
            
            while( enable.size()>1 && enable[1].idx <= idx )
                enable.erase(enable.begin());
            
            if(enable[0].enabled)
                total += do_the_mul(line,idx+3);
        }
    }
    
    std::cout << "Part two answer: " << total << std::endl;
    
    
}













