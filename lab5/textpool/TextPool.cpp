//
// Created by igor on 03.04.18.
//

#include "TextPool.h"

pool::TextPool::TextPool() {
    data_=new std::set<std::experimental::string_view>;
}

pool::TextPool::TextPool(pool::TextPool &&other) {
    data_= nullptr;
    std::swap(data_, other.data_);
}

pool::TextPool &pool::TextPool::operator=(pool::TextPool &&other) {
    if (this==&other){
        return *this;
    }
    data_= nullptr;
    std::swap(data_, other.data_);
}

pool::TextPool::~TextPool() {
    delete data_;
}

pool::TextPool::TextPool(std::initializer_list<std::string> strings) {
    data_= new std::set<std::experimental::string_view>;
    for (const std::string &element : strings){
        std::experimental::string_view strv(element);
        data_->insert(strv);
    }
}

std::experimental::string_view pool::TextPool::Intern(const std::string &str) {
    std::experimental::string_view strv(str);
    data_->insert(strv);
    return *data_->find(strv);
}

size_t pool::TextPool::StoredStringCount() const {
    return  data_->size();
}
