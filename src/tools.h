#include <string>
#include <iostream>
void debug(std::string comment){
    std::cout << comment << '\n';
}

void debug(char* comment){
    std::cout << comment << '\n';
}

void debug(char comment){
    std::cout << comment << '\n';
}

void debug(int comment){
    std::cout << comment << '\n';
}

void debugWait(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}