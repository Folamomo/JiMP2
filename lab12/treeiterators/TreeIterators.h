//
// Created by igor on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <memory>
#include <vector>
#include <Tree.h>

namespace tree{
    template <class T>
class InOrderTreeIterator{
    public:
        explicit InOrderTreeIterator(Tree<T> *root){
            OrderFiller(root);
            position = 0;
        }

        void OrderFiller(Tree<T>* node){
            if (node->left_child_!=nullptr) OrderFiller(node->left_child_.get());
            order_.emplace_back(node);
            if (node->right_child_!=nullptr) OrderFiller(node->right_child_.get());
        }

        InOrderTreeIterator<T> JumpToEnd(){
            position = order_.size();
            return *this;
        }

        InOrderTreeIterator<T> operator ++ (){
            position++;
            return *this;
        }
        T operator *(){
            return order_[position]->Value();
        }
        bool operator != (const InOrderTreeIterator& other) const{
            return position!=other.position;
        }
    private:
        std::vector<Tree<T>*> order_;
        size_t position;
    };

    template <class T>
    class InOrderTreeView{
    public:
        explicit InOrderTreeView(Tree<T> *tree) :root_(tree){}

        InOrderTreeIterator<T> begin(){
            return InOrderTreeIterator<T>(root_);
        }
        InOrderTreeIterator<T> end(){
            return InOrderTreeIterator<T>(root_).JumpToEnd();
        }

    private:
        Tree<T> *root_;
    };

    template <class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree){
        return InOrderTreeView<T>(tree);
    }
}


#endif //JIMP_EXERCISES_TREEITERATORS_H
