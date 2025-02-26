#ifndef UCM_RANDOM_H
#define UCM_RANDOM_H

#include <cstdlib>
#include <ctime>

struct RNG{
    RNG(){
        srand(time(NULL));
    }
    int get(int min = 1, int max = 10){
        int random_number = rand() % (max - min + 1) + min;

        return random_number;
    }
};

#endif