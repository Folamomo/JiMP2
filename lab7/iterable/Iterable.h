//
// Created by igor on 21.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <utility>
#include <string>
#include <vector>
#include <memory>

namespace utility{
class IterableIterator {
public:
    virtual std::pair<int, std::string> Dereference() const  =0;
    virtual IterableIterator &Next() =0;
    virtual bool NotEquals(const IterableIterator &other) const =0;
    virtual ~IterableIterator()= default;
};

class ZipperIterator:public IterableIterator{
    explicit ZipperIterator(std::vector<int>::const_iterator left,
                            std::vector<std::string>::const_iterator right,
                            std::vector<int>::const_iterator left_end,
                            std::vector<std::string>::const_iterator right_end);
};
}

#endif //JIMP_EXERCISES_ITERABLE_H
