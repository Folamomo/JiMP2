//
// Created by igor on 06.03.18.
//

#include "Palindrome.h"
#include <ReverseString.h>
#include <string>

bool is_palindrome(std::string str){
    std::string reversed = reverse(str);
    if(str.compare(reversed) == 0){
        return 1;
    }else{
        return 0;
    }

}