#ifndef MONOTONIC_H
#define MONOTONIC_H

#include <vector>

static bool is_increasing(std::vector<int> checkMe){
    for(int i = 1; i < checkMe.size(); i++)
        if(checkMe[i]<checkMe[i-1])
            return false;
    return true;
}

static bool is_decreasing(std::vector<int> checkMe){
    for(int i = 1; i < checkMe.size(); i++)
        if(checkMe[i]>checkMe[i-1])
            return false;
    return true;
}

static bool is_strictly_increasing(std::vector<int> checkMe){
    for(int i = 1; i < checkMe.size(); i++)
        if(checkMe[i]<=checkMe[i-1])
            return false;
    return true;
}

static bool is_strictly_decreasing(std::vector<int> checkMe){
    for(int i = 1; i < checkMe.size(); i++)
        if(checkMe[i]>=checkMe[i-1])
            return false;
    return true;
}

static bool is_monotonic(std::vector<int> checkMe){ return is_increasing(checkMe) || is_decreasing(checkMe); };
static bool is_strictly_monotonic(std::vector<int> checkMe){ return is_strictly_increasing(checkMe) || is_strictly_decreasing(checkMe); };

#endif//MONOTONIC_H

