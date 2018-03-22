//
// Created by igor on 20.03.18.
//

#include "XorCypherBreaker.h"
#include <algorithm>

bool DictSearch(std::vector<std::string> &words, const std::vector<std::string> &dictionary) {
    for (std::string word : words) {
        if (find(dictionary.begin(), dictionary.end(), word) != dictionary.end()) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> ExtractWords(const std::vector<char> &cryptogram,
                                      int key_length, const char *key){
    int i=0;
    std::vector<std::string> words;
    std::string word;
    for (char c : cryptogram){

        char decrypted = c | key[i];
        if (decrypted!=' '){
            word += decrypted;
        }else{
            words.push_back(word);
            word="";
        }
        i=(i+1)%key_length;
    }
    return words;
}

void IncrementKey(char *key) {
    if (*key=='z') {
        *key = 'a';
        IncrementKey(key + 1);
    } else {
        (*key)++;
    }
}


std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary){
    char key[key_length+1];
    for (int i = 0; i < key_length+1; ++i) {
        key[i]='a';
    }
    while (key[key_length]=='a'){
        std::vector<std::string> words=ExtractWords(cryptogram, key_length, key);
        if(DictSearch(words, dictionary)){
            std::string result;
            for (int i = 0; i < key_length; ++i) {
                result+=key[i];
            }
            return result;
        }
        IncrementKey(key);
    }
}