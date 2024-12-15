#include "../AoC.h"

int find_2d_str( std::vector<std::string> searchMe, std::vector<std::string> findMe ){
    int retMe = 0;
    
    for( int y = 0; y < searchMe.size()-findMe.size()+1; y++ ){
        for( int x = 0; x < searchMe[0].size()-findMe[0].size()+1; x++ ){
            bool is_match = true;
            
            for( int i = 0; i < findMe.size(); i++ ){
                for( int j = 0; j < findMe.size(); j++ ){
                    if( !(findMe[i][j] == '.' || findMe[i][j] == searchMe[y+i][x+j]) ) is_match = false;
                }
            }
            
            if( is_match ) retMe++;
        }
    }
    
    return retMe;
}

int main(){
    
    int total = 0;
    
    auto arr = read_input(4);
    //auto arr = read_test(4,1);
    
    std::string findMe = "XMAS";
    
    for( int y = 0; y < arr.size(); y++ ){
        for( int x = 0; x < arr[0].size(); x++ ){
            
            //std::cout << arr[y][x];
            
            bool is_up_left = true;
            if( y < findMe.size()-1 || x < findMe.size()-1 ) goto left;
            for(int i = 0; i < findMe.size(); i++){
                if( findMe[i] != arr[y-i][x-i] ) is_up_left = false;
            }
            if( is_up_left ){
                //std::cout << x << " " << y ;
                total++;
            }
            
            left:;
            bool is_left = true;
            if( x < findMe.size()-1 ) goto down_left;
            for(int i = 0; i < findMe.size(); i++){
                if( findMe[i] != arr[y][x-i] ) is_left = false;
            }
            if( is_left ){
                total++;
            }
            
            down_left:;
            bool is_down_left = true;
            if( y > arr.size()-findMe.size() || x < findMe.size()-1 ) goto down;
            for(int i = 0; i < findMe.size(); i++){
                if( findMe[i] != arr[y+i][x-i] ) is_down_left = false;
            }
            if( is_down_left ){
                total++;
            }
            
            down:;
            bool is_down = true;
            if( y > arr[0].size()-findMe.size() ) goto down_bad;
            for(int i = 0; i < findMe.size(); i++){
                if( findMe[i] != arr[y+i][x] ) is_down = false;
            }
            if( is_down ){
                total++;
            }
            
            down_bad:;
            bool is_down_right = true;
            if( y > arr.size()-findMe.size() || x > arr[0].size()-findMe.size() ) goto right;
            for(int i = 0; i < findMe.size(); i++){
                if( findMe[i] != arr[y+i][x+i] ) is_down_right = false;
            }
            if( is_down_right ){
                total++;
            }
            
            right:;
            bool is_right = true;
            if( x > arr[0].size()-findMe.size()-1 ) goto up_right;
            for(int i = 0; i < findMe.size(); i++){
                if( findMe[i] != arr[y][x+i] ) is_right = false;
            }
            if( is_right ){
                total++;
            }
            
            up_right:;
            bool is_up_right = true;
            if( y < findMe.size()-1 || x > arr[0].size()-findMe.size() ) goto up;
            for(int i = 0; i < findMe.size(); i++){
                if( findMe[i] != arr[y-i][x+i] ) is_up_right = false;
            }
            if( is_up_right ){
                total++;
            }
            
            up:;
            bool is_up = true;
            if( y < findMe.size()-1 ) goto fin;
            for(int i = 0; i < findMe.size(); i++){
                if( findMe[i] != arr[y-i][x] ) is_up = false;
            }
            if( is_up ){
                total++;
            }
            
            fin:;
        }
        //std::cout << "\n";
    }
    
    
    
    
    std::cout << "Part one answer: " << total << std::endl;
    total = 0;
    
    std::vector<std::string> x1 = {
        "M.M",
        ".A.",
        "S.S"
    };
    
    std::vector<std::string> x2 = {
        "M.S",
        ".A.",
        "M.S"
    };
    
    std::vector<std::string> x3 = {
        "S.S",
        ".A.",
        "M.M"
    };
    
    std::vector<std::string> x4 = {
        "S.M",
        ".A.",
        "S.M"
    };

    total += find_2d_str( arr, x1 );
    total += find_2d_str( arr, x2 );
    total += find_2d_str( arr, x3 );
    total += find_2d_str( arr, x4 );
    
    
    std::cout << "Part two answer: " << total << std::endl;
}
