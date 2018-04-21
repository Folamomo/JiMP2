//
// Created by igor on 21.04.18.
//

#include "Zipper.h"
/*
datastructures::Zipper datastructures::Zipper::zip(const std::vector<std::string> &vs, const std::vector<int> &vi) {
    Zipper output{};
    for (int i = 0; i < (vs.size() > vi.size() ? vs.size() : vi.size()); ++i) {
        output.zipdata_.emplace_back("", 0);
    }
    int i=0;
    for (const std::string &s:vs){
        output.zipdata_[i].first=s;
        ++i;
    }
    i=0;
    for (int a:vi){
        output.zipdata_[i].second=a;
        ++i;
    }
    return output;
}
*/




datastructures::Zipper datastructures::Zipper::zip(const std::vector<std::string> &vs, const std::vector<int> &vi) {
    Zipper output{};
    for (int i = 0; i < (vs.size() > vi.size() ? vs.size() : vi.size()); ++i) {
        output.vs_.emplace_back("");
        output.vi_.emplace_back(0);
    }
    int i=0;
    for (const std::string &s:vs){
        output.vs_[i]=s;
        ++i;
    }
    i=0;
    for (int a:vi){
        output.vi_[i]=a;
        ++i;
    }
    return output;
}

datastructures::ZipperIterator datastructures::Zipper::begin() {
    return datastructures::ZipperIterator(&(vs_.front()),&(vi_.front()));
}

datastructures::ZipperIterator datastructures::Zipper::end() {
    return datastructures::ZipperIterator(&(vs_.back()),&(vi_.back()));
}

datastructures::ZipperIterator::ZipperIterator(std::string *s, int *i) {
    s_=s;
    i_=i;
}

std::pair<std::string, int> datastructures::ZipperIterator::operator*() const {
    return std::make_pair(*(s_), *(i_));
}

bool datastructures::ZipperIterator::operator!=(const datastructures::ZipperIterator &other) const {
    return !(s_ != other.s_ || i_ != other.i_);
}

datastructures::ZipperIterator &datastructures::ZipperIterator::operator++() {
    ++i_;
    ++s_;
    return *this;
}
