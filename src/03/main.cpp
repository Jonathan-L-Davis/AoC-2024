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
    //auto d = read_test(3,4);
    int64_t total = 0;
    for(auto line : d){
        
        auto line_idx = get_substr_locations(line,"mul");
        for(auto idx : line_idx){
            total += do_the_mul(line,idx+3);
        }
        
    }
    
    std::cout << "Part one answer: " << total << std::endl;
    total = 0;
    std::string p;
    for(auto d_str:d)p+=" "+d_str;
    d={p};
    
    bool enable_persist = true;
    for(auto line : d){
        
        auto mul_idx = get_substr_locations(line,"mul");
        
        auto dont_idx = get_substr_locations(line,"don't()");
        auto does_idx = get_substr_locations(line,"do()");
        
        std::vector<enabler> enable = {{enable_persist,0}};
        //std::cout << enable_persist << std::endl;
        std::vector<int> enable_idx={};
        //assuming they cannot share idx's (cuz they can't)
        while( dont_idx.size() > 0 || does_idx.size() > 0 ){
            if( dont_idx.size()>0 && does_idx.size()>0 ){
                if( dont_idx[0] < does_idx[0] ){
                    enable.push_back({false,dont_idx[0]});
                    enable_idx.push_back(dont_idx[0]);
                    //std::cout << "c1: " << dont_idx[0] << std::endl;
                    dont_idx.erase(dont_idx.begin());
                }
                else if( dont_idx[0] > does_idx[0] ){
                    enable.push_back({true,does_idx[0]});
                    enable_idx.push_back(does_idx[0]);
                    //std::cout << "c2: " << does_idx[0] << std::endl;
                    does_idx.erase(does_idx.begin());
                }else assert(false);
            }else if(dont_idx.size()>0){
                enable.push_back({false,dont_idx[0]});
                enable_idx.push_back(dont_idx[0]);
                    //std::cout << "c3: " << dont_idx[0] << std::endl;
                break;
            }else if(does_idx.size()>0){
                enable.push_back({true,does_idx[0]});
                enable_idx.push_back(dont_idx[0]);
                    //std::cout << "c4: " << does_idx[0] << std::endl;
                break;
            }else assert(false);
        }
        //
        assert(is_increasing(enable_idx));
        //std::cout << "\n\n\n\n\n\n\n\n\n\n";for( auto l : enable ) std::cout << l.enabled << ":" << l.idx << std::endl;
        for(auto idx : mul_idx){
            
            while( enable.size()>1 && enable[1].idx < idx ){
                enable.erase(enable.begin());
            }
            
            if(enable[0].enabled){
                total += do_the_mul(line,idx+3);
            }
            //enable_persist = enable[0].enabled;
        }
    }
    
    std::cout << "Part two answer: " << total << std::endl;
    
    
}













