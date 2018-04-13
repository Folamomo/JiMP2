//
// Created by igor on 12.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <algorithm>
#include <regex>
#include <iostream>
#include <initializer_list>
#include <set>
#include <string>

namespace datastructures {
    class Word {
    public:
        Word(std::string str);
        bool operator < (const datastructures::Word &other) const;
        bool operator > (const datastructures::Word &other) const;
        bool operator == (const datastructures::Word &other) const;
    private:
        std::string data_;
    };

    class Counts {
    public:
        Counts();
        Counts(int i);
        int get() const;
        Counts operator ++ ();
        bool operator <(const datastructures::Counts &other) const;
        bool operator >(const datastructures::Counts &other) const;
        bool operator ==(const datastructures::Counts &other) const;
        friend bool operator == (int i, Counts c);
    private:
        int data_;
    };

    bool operator == (int i, Counts c);

    class WordCounter {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> initlist);
        int DistinctWords() const ;
        int TotalWords() const ;
        std::set<datastructures::Word> Words() const;
        Counts operator[](std::string key);
    private:
        std::map<datastructures::Word, datastructures::Counts> map_;
    };
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
