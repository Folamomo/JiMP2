//
// Created by igor on 06.03.18.
//

#include "Palindrome.h"
#include <ReverseString.h>
#include <string>

bool is_palindrome(std::string str){
    std::string reversed = reverse(str);
    return str == reversed;

}