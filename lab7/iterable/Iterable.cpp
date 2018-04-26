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
    left_end_=left_end;
    right_end_=right_end;
}


std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    return std::make_pair(*left_, *right_);
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    ++left_;
    ++right_;
    if(left_==left_end_&&right_!=right_end_){
        --left_;
    } else if (right_==right_end_&&left_!=left_end_){
        --right_;
    }
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    return (right_!=other->right_||left_!=other->left_);
}

utility::EnumerateIterator::EnumerateIterator(std::vector<std::string>::const_iterator right,
                                              std::vector<std::string>::const_iterator right_end) {
    right_=right;
    right_end_=right_end;
    index_=1;
}

std::pair<int, std::string> utility::EnumerateIterator::Dereference() const {
    return std::make_pair(index_,*right_);
}

utility::IterableIterator &utility::EnumerateIterator::Next() {
    ++right_;
    ++index_;
    return *this;
}

bool utility::EnumerateIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    return right_!=other->right_;
}

utility::ProductIterator::ProductIterator(std::vector<int>::const_iterator left,
                                          std::vector<std::string>::const_iterator right,
                                          std::vector<int>::const_iterator left_end,
                                          std::vector<std::string>::const_iterator right_end) {
    left_=left;
    right_=right;
    left_end_=left_end;
    right_end_=right_end;
    right_begin_=right;
}

std::pair<int, std::string> utility::ProductIterator::Dereference() const {
    return std::make_pair(*left_,*right_);
}

utility::IterableIterator &utility::ProductIterator::Next() {
    ++right_;
    if(right_==right_end_){
        right_=right_begin_;
        ++left_;
    }
    if(left_==left_end_){
        right_=right_end_;
    }
    return *this;
}



bool utility::ProductIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
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

utility::Zipper::Zipper(const std::vector<int> &vi, const std::vector<std::string> &vs) {
    vi_=&vi;
    vs_=&vs;
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    ZipperIterator zit (vi_->begin(),vs_->begin(), vi_->end(), vs_->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
    return ptr;
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    ZipperIterator zit (vi_->end(),vs_->end(), vi_->end(),vs_->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
    return ptr;
}

utility::Enumerate::Enumerate(const std::vector<std::string> &vs) {
    vs_=&vs;
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstBegin() const {
    EnumerateIterator eit (vs_->begin(),vs_->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<EnumerateIterator>(eit);
    return ptr;
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstEnd() const {
    EnumerateIterator eit (vs_->end(), vs_->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<EnumerateIterator>(eit);
    return ptr;
}

utility::Product::Product(const std::vector<int> &vi, const std::vector<std::string> &vs) {
    vi_=&vi;
    vs_=&vs;
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstBegin() const {
    ProductIterator pit (vi_->begin(),vs_->begin(), vi_->end(), vs_->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ProductIterator>(pit);
    return ptr;
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstEnd() const {
    ProductIterator pit (vi_->end(), vs_->end(), vi_->end(), vs_->end());
    std::unique_ptr<IterableIterator> ptr = std::make_unique<ProductIterator>(pit);
    return ptr;
}
