//
// Created by igor on 06.03.18.
//

#include "Polybius.h"

int PointerToIndeks(const char *c){
    int indeks = -1;
    if (*c>='A' && *c<='I'){
        indeks = *c-'A';
    } else if (*c>='J' && *c<='Z'){
        indeks = *c - 'A'-1;
    } else if (*c>='a' && *c<='i'){
        indeks = *c-'a';
    } else if (*c>='j' && *c<='z'){
        indeks = *c - 'a'-1;
    }
    return indeks;
}

std::string IndexToValue(int index){
    if (index>=0){
        int a = 0;
        a=(index/5+1)*10+index%5+1;
        return std::to_string(a);
    }
    else return "";
}

std::string PolybiusCrypt(std::string message){
    const char* characters = (message.c_str());
    std::string output;
    for (int i = 0; i < message.length(); ++i) {
        char c;
        int indeks = PointerToIndeks(characters + i);
        output += IndexToValue(indeks);
    }
    return output;
}


std::string PolybiusDecrypt(std::string crypted){

}
