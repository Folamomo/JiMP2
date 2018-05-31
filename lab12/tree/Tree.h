//
// Created by igor on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>

namespace tree {
    template <class T>
    class Tree {
    public:
        explicit Tree() : left_child_(nullptr), right_child_(nullptr){}
        explicit Tree(T value) : value_(value),  right_child_(nullptr), left_child_(nullptr){}

        T& Value() {
            return value_;
        }

        size_t Size() {
            if (left_child_ == nullptr and right_child_ == nullptr) {
                return 1;
            } else if (right_child_ == nullptr) {
                return left_child_->Size()+1;
            } else if (left_child_ == nullptr) {
                return right_child_->Size()+1;
            } else {
                return left_child_->Size() + right_child_->Size()+1;
            }
        }

        size_t Depth() {
            if (left_child_ == nullptr and right_child_ == nullptr) {
                return 1;
            } else if (right_child_ == nullptr) {
                return left_child_->Depth()+1;
            } else if (left_child_ == nullptr) {
                return right_child_->Depth()+1;
            } else {
                return std::max(left_child_->Depth() , right_child_->Depth())+1;
            }
        }
        void Insert(T to_insert){
            if (to_insert<value_){
                if (left_child_== nullptr){
                    left_child_ = std::make_unique<Tree<T>>(to_insert);;
                } else left_child_->Insert(to_insert);
            } else {if (right_child_== nullptr){
                    right_child_ = std::make_unique<Tree<T>>(to_insert);;
                } else right_child_->Insert(to_insert);
            }
        }

        Tree <T>* Root (){
            return this;
        }

        std::unique_ptr<Tree <T>> left_child_;
        std::unique_ptr<Tree <T>> right_child_;
    private:
        T value_;
    };
}

#endif //JIMP_EXERCISES_TREE_H
