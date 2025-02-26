#ifndef UCM_UTILS_H
#define UCM_UTILS_H

#include <iostream>

void progess(int percent) {
    int stage = percent / 10;

    std::cout << "[";
    for (int i = 1; i <= stage; i++) {
        std::cout << "=";
    }
    for (int i = stage + 1; i <= 10; i++) {
        std::cout << " ";
    }
    std::cout << "]";

    std::cout << " | " << percent << "%" << std::endl << std::endl;
}



void banner(std::string heading){
    for (int i = 0; i < heading.length() + 2; i++){
        std::cout << "=";
    }
    std::cout << std::endl;

    std::cout << " " << heading << " " << std::endl;

    for (int i = 0; i < heading.length() + 2; i++){
        std::cout << "=";
    }
    std::cout << std::endl;
}


void showHeading(){
    system("clear");
    banner("University of California, Merced");
    std::cout << std::endl;
}

/*
    Your code goes here
*/

#endif