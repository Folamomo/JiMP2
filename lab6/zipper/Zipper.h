//
// Created by igor on 21.04.18.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <string>
#include <vector>
#include <utility>

namespace datastructures {
    class ZipperIterator{
    public:
        ZipperIterator(std::string *s, int * i);
        std::pair<std::string,int> operator*() const;
        ZipperIterator &operator++();
        bool operator!=(const ZipperIterator &other) const;
    private:
        std::string *s_;
        int *i_;
    };

    class Zipper {
    public:
        static Zipper zip(const std::vector<std::string> &vs, const std::vector<int> &vi);
        ZipperIterator begin();
        ZipperIterator end();
    private:
        std::vector<std::string> vs_;
        std::vector<int> vi_;
        size_t size_;
    };
}

#endif //JIMP_EXERCISES_ZIPPER_H
