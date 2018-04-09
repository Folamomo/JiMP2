//
// Created by igor on 03.04.18.
//

#include "TextPool.h"

pool::TextPool::TextPool() {

}

pool::TextPool::TextPool(pool::TextPool &&other) {
    std::swap(data_, other.data_);
}

pool::TextPool & pool::TextPool::operator=(pool::TextPool &&other) {
    if (this==&other){
        return *this;
    }
    std::swap(data_, other.data_);
    return *this;
}

pool::TextPool::~TextPool() {

}

pool::TextPool::TextPool(const std::initializer_list<std::experimental::string_view> &elements) {

    data_ = elements;

}

std::experimental::string_view pool::TextPool::Intern(const std::string &str) {
    std::experimental::string_view strv(str);
    data_.insert(strv);
    return *data_.find(strv);
}

size_t pool::TextPool::StoredStringCount() const {
    return  data_.size();
}

