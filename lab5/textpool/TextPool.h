//
// Created by igor on 03.04.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool {
    class TextPool {
    public:
        TextPool();
        TextPool(TextPool &&other);

        TextPool &operator=(TextPool &&other);

        ~TextPool();

        TextPool(const std::initializer_list<std::experimental::string_view> &elements);

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;


    private:
        std::set<std::experimental::string_view> data_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
