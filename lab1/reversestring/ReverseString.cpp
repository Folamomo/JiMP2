//
// Created by igor on 04.03.18.
//

#include <string>
#include <ReverseString.h>
#include <algorithm>

std::string reverse(std::string str){
    std::reverse(str.begin(), str.end());
    return str;
}
