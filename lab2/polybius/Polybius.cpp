//
// Created by igor on 06.03.18.
//

#include "Polybius.h"


std::string encryptOneChar(char c){
    std::string output;
    int indeks = -1;
    if (c>='A' && c<='I'){
        indeks = c-'A';
    } else if (c>='J' && c<='Z'){
        indeks = c - 'A'-1;
    } else if (c>='a' && c<='i'){
        indeks = c-'a';
    } else if (c>='j' && c<='z'){
        indeks = c - 'a'-1;
    }
    if (indeks<0){
        return output;
    }
    int rowNumber = indeks/5+1;
    int columnNumber = indeks % 5 +1;
    output += std::to_string(rowNumber);
    output += std::to_string(columnNumber);
    return output;
}

char decryptOneChar(const char *c){
    int rowNumber = *c - '0';
    int columnNumber = *(c+1) - '0';
    char character = 'a' + (rowNumber-1)*5+columnNumber-1;
    if (character>='j') ++character;
    return  character;
}

std::string PolybiusCrypt(std::string message){
    const char* characters = (message.c_str());
    std::string output;
    for (int i = 0; i < message.length(); ++i) {
        output += encryptOneChar(*(characters+i));
    }
    return output;
}


std::string PolybiusDecrypt(std::string crypted){
    const char* characters = (crypted.c_str());
    std::string output;
    for (int i = 0; i < crypted.length(); i+=2) {
        output += decryptOneChar(characters + i);
    }
    return output;
}
