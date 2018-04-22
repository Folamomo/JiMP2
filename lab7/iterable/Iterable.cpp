//
// Created by igor on 21.04.18.
//

#include "Iterable.h"


utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                        std::vector<std::string>::const_iterator right,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {
    left_=left;
    right_=right;
}

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                        std::vector<std::string>::const_iterator right) {
    left_=left;
    right_=right;
}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    return std::make_pair(*left_, *right_);
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    ++left_;
    ++right_;
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    return (right_!=other->right_||left_!=other->left_);
}

utility::IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iterator_=move(iterator);
}

bool utility::IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) const {
    return iterator_->NotEquals(other.iterator_);
}

std::pair<int, std::string> utility::IterableIteratorWrapper::operator*() const {
    return iterator_->Dereference();
}

utility::IterableIteratorWrapper &utility::IterableIteratorWrapper::operator++() {
    iterator_->Next();
    return *this;
}

utility::IterableIteratorWrapper utility::Iterable::cbegin() const {
    return utility::IterableIteratorWrapper(ConstBegin());
}

utility::IterableIteratorWrapper utility::Iterable::cend() const {
    return utility::IterableIteratorWrapper(ConstEnd());
}

utility::IterableIteratorWrapper utility::Iterable::begin() const {
    return cbegin();
}

utility::IterableIteratorWrapper utility::Iterable::end() const {
    return cend();
}

utility::Zipper::Zipper(std::vector<int> vi, std::vector<std::string> vs) {
    vi_=vi;
    vs_=vs;
    if (vi_.size()>vs_.size()){
        for (auto i=vs_.size(); i<vi_.size(); ++i){
            vs_.emplace_back(vs.back());
        }
    }else{
        for (auto i = vi_.size(); i < vs_.size(); ++i) {
            vi_.emplace_back(vi.back());
        }
    }
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    ZipperIterator zit (vi_.begin(),vs_.begin());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
    return ptr;
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    ZipperIterator zit (vi_.end(),vs_.end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
    return ptr;
}

utility::Enumerate::Enumerate(std::vector<std::string> vs) {
    vs_=vs;
    for (int i=0;i<vs_.size();++i){
        vi_.emplace_back(i+1);
    }
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstBegin() const {
    ZipperIterator zit (vi_.begin(),vs_.begin());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
    return ptr;
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstEnd() const {
    ZipperIterator zit (vi_.end(),vs_.end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
    return ptr;
}

utility::Product::Product(std::vector<int> vi, std::vector<std::string> vs) {
    for (auto i:vi){
        for (auto s:vs){
            vi_.emplace_back(i);
            vs_.emplace_back(s);
        }
    }
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstBegin() const {
    ZipperIterator zit (vi_.begin(),vs_.begin());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
    return ptr;
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstEnd() const {
    ZipperIterator zit (vi_.end(),vs_.end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
    return ptr;
}
