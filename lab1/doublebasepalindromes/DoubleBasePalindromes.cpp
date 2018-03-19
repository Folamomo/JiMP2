//
// Created by igor on 06.03.18.
//

#include "DoubleBasePalindromes.h"
#include <string>
#include <Palindrome.h>
#include <ReverseString.h>

std::string ToBinStr(int number){
    std::string result;
    while (number>0){
        result += std::to_string(number%2);
        number>>=1;
    }
    return reverse(result);
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum = 0;
    for (int i = 0; i < max_vaule_exculsive; ++i)
        if(is_palindrome( std::to_string(i)))
            if (is_palindrome(ToBinStr(i)))
                sum += i;
    return sum;
}

