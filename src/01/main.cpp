#include <iostream>
#include <algorithm>
#include "../AoC.h"
#include <assert.h>
#include <map>

int main(){
    std::vector my_locations = read_input(1);
    std::vector<int> l1;
    std::vector<int> l2;
    
    for( int i = 0; i < my_locations.size(); i++ ){
        assert(split(my_locations[i]," ").size()==2);
        l1.push_back( std::stoi(split(my_locations[i]," ")[0]) );
        l2.push_back( std::stoi(split(my_locations[i]," ")[1]) );
    }
    
    std::sort( std::begin(l1), std::end(l1) );
    std::sort( std::begin(l2), std::end(l2) );
    
    int total = 0;
    for( int i = 0; i < l1.size(); i++){
        total += std::abs( l1[i]-l2[i] );
    }
    std::cout << "Part one answer: " << total << std::endl;
    
    total = 0;
    
    std::map<int,int> idx;
    for( int elem : l1 ){
        
        for( int i : l2 )
            if( elem == i )
                idx[elem] += elem;
        
    }
    
    for( auto [key, value] : idx )
        total += value;
    
    std::cout << "Part two answer: " << total << std::endl;
}

