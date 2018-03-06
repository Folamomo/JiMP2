//
// Created by igor on 06.03.18.
//

#include "DoubleBasePalindromes.h"
#include <string>
#include <Palindrome.h>


uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    for (int i = 0; i < max_vaule_exculsive; ++i) {
        std::string str = std::to_string(i);
        if(is_palindrome(str)){
            
        }
    }
    return 0;
}