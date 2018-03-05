//
// Created by igor on 04.03.18.
//

#include <string.h>
#include <iostream>

char recreverse(char *pointer){
    if (*pointer == '\o')
        return;
    else
        return recreverse(pointer+1)+pointer;
}

std::string reverse(std::string str){
    const char *characters = str.c_str();
    return std::string(recreverse(characters));
}
