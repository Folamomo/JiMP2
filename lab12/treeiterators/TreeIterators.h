//
// Created by igor on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <memory>
#include <Tree.h>

namespace tree{
    template <class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(const Tree<T> &root, bool is_end) :node_(root), is_end_(is_end){
            if (is_end_){
                while (node_.right_child_!= nullptr){
                    
                }
            }
        }
        InOrderTreeIterator<T> operator ++ (){

        }
        T operator *(){
            return node_->Value();
        }
        bool operator != (const InOrderTreeIterator& other){
            return &node_!=&other.node_ or is_end_!=other.is_end_;
        }
    private:
        const Tree<T> &node_;
        bool visited_right_;
        std::vector <const Tree<T>&> root_path_;
        bool is_end_;
    };

    template <class T>
    class InOrderTreeView{
    public:
        explicit InOrderTreeView(Tree<T> *tree){
            root_=tree;
        }
        InOrderTreeIterator<T> begin(){
            return InOrderTreeIterator(*root_, false);
        }
        InOrderTreeIterator<T> end(){
            return InOrderTreeIterator(*root_, true);
        }

    private:
        Tree<T>* root_;
    };

    template <class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree){
        return InOrderTreeView<T>(tree);
    }
}


#endif //JIMP_EXERCISES_TREEITERATORS_H
