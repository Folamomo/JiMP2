//
// Created by igor on 17.04.18.
//

#include <cstddef>
#include "ArrayFill.h"

void arrays::FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
    v->clear();
    v->reserve(size);
    for (size_t i = 0; i < size; i++) {
        v->emplace_back(filler.Value(i));
    }
}

int arrays::UniformFill::Value(int index) const {
    return number_;
}

arrays::UniformFill::UniformFill(int number) {
    number_=number;
}

arrays::IncrementalFill::IncrementalFill(int start, int increment) {
    start_=start;
    increment_=increment;
}

int arrays::IncrementalFill::Value(int index) const {
    return start_+increment_*index;
}

arrays::SquaredFill::SquaredFill(int factor, int offset) {
    factor_=factor;
    offset_=offset;
}

int arrays::SquaredFill::Value(int index) const {
    return factor_*index*index+offset_;
}

arrays::RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> engine,
                               std::unique_ptr<std::uniform_int_distribution<int>> dist) {
    engine_=move(engine);
    dist_=move(dist);
}

int arrays::RandomFill::Value(int index) const {
    return (*dist_)(*engine_);
}
