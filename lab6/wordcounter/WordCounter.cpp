//
// Created by igor on 12.04.18.
//


#include "WordCounter.h"

datastructures::Counts::Counts() {
    data_=0;
}

datastructures::Counts::Counts(int i) {
    data_=i;
}

datastructures::Counts datastructures::Counts::operator++() {
    data_++;
    return *this;
}

bool datastructures::Counts::operator<(const datastructures::Counts &other) const {
    return data_ < other.data_;
}

bool datastructures::Counts::operator==(const datastructures::Counts &other) const {
    return data_ == other.data_;
}

bool datastructures::Counts::operator>(const datastructures::Counts &other) const {
    return data_ > other.data_;
}

int datastructures::Counts::get() const {
    return data_;
}

bool datastructures::operator==(int i, datastructures::Counts c) {
    return i==c.get();
}


int datastructures::WordCounter::DistinctWords() const{
    return (int)map_.size();
}

int datastructures::WordCounter::TotalWords() const{
    int result=0;
    for (const auto &pair:this->map_){
        result +=pair.second.get();
    }
    return result;
}

std::set<datastructures::Word> datastructures::WordCounter::Words() const{
    std::set<datastructures::Word> result;
    for (const auto &pair:this->map_){
        result.insert(pair.first);
    }
    return result;
}

datastructures::WordCounter::WordCounter(std::initializer_list<Word> initlist) {
    for(auto& word:initlist){
        map_.insert(std::make_pair(word, datastructures::Counts()));
        ++(map_.find(word)->second);
    }
}

datastructures::WordCounter::WordCounter() {

}

datastructures::Counts datastructures::WordCounter::operator[](std::string key) {
    if (map_.count(key)==0)
        return 0;
    return map_.find(key)->second;
}


datastructures::Word::Word(std::string str) {
    data_=str;
}

bool datastructures::Word::operator<(const datastructures::Word &other) const {
    if(data_.compare(other.data_)>0){
        return 1;
    } else {
        return 0;
    }

}

bool datastructures::Word::operator>(const datastructures::Word &other) const {
    if(data_.compare(other.data_)<0){
        return 1;
    } else {
        return 0;
    }

}


bool datastructures::Word::operator==(const datastructures::Word &other) const {
    if(data_.compare(other.data_)==0){
        return 1;
    } else{
        return 0;
    }
}


