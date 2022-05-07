#include<iostream>
#include <string>
#include <chrono>
#include <future>
    #include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>
#include "kbhit.h"
#include <stdio.h>


int key_press() {
    system("stty raw");
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = now + std::chrono::milliseconds(200);
    char c,d;

    while(end > now){
        d = getchar();
        if(d == 'a' || d== 'x')
            c = d;
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    }

    system("stty cooked");
    // std::string input; 
    // std::getline(std::cin, input);
    return c;
}


int Input(){
    if (kbhit())
    {
        return getchar();
    }
    return -1;
}