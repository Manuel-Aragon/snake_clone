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