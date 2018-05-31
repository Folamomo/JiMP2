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


    template <class T>
    class PreOrderTreeIterator{
    public:
        explicit PreOrderTreeIterator(Tree<T> *root){
            OrderFiller(root);
            position = 0;
        }

        void OrderFiller(Tree<T>* node){
            order_.emplace_back(node);
            if (node->left_child_!=nullptr) OrderFiller(node->left_child_.get());
            if (node->right_child_!=nullptr) OrderFiller(node->right_child_.get());
        }

        PreOrderTreeIterator<T> JumpToEnd(){
            position = order_.size();
            return *this;
        }

        PreOrderTreeIterator<T> operator ++ (){
            position++;
            return *this;
        }
        T operator *(){
            return order_[position]->Value();
        }
        bool operator != (const PreOrderTreeIterator& other) const{
            return position!=other.position;
        }
    private:
        std::vector<Tree<T>*> order_;
        size_t position;
    };

    template <class T>
    class PreOrderTreeView{
    public:
        explicit PreOrderTreeView(Tree<T> *tree) :root_(tree){}

        PreOrderTreeIterator<T> begin(){
            return PreOrderTreeIterator<T>(root_);
        }
        PreOrderTreeIterator<T> end(){
            return PreOrderTreeIterator<T>(root_).JumpToEnd();
        }

    private:
        Tree<T> *root_;
    };

    template <class T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree){
        return PreOrderTreeView<T>(tree);
    }

    template <class T>
    class PostOrderTreeIterator{
    public:
        explicit PostOrderTreeIterator(Tree<T> *root){
            OrderFiller(root);
            position = 0;
        }

        void OrderFiller(Tree<T>* node){
            if (node->left_child_!=nullptr) OrderFiller(node->left_child_.get());
            if (node->right_child_!=nullptr) OrderFiller(node->right_child_.get());
            order_.emplace_back(node);
        }

        PostOrderTreeIterator<T> JumpToEnd(){
            position = order_.size();
            return *this;
        }

        PostOrderTreeIterator<T> operator ++ (){
            position++;
            return *this;
        }
        T operator *(){
            return order_[position]->Value();
        }
        bool operator != (const PostOrderTreeIterator& other) const{
            return position!=other.position;
        }
    private:
        std::vector<Tree<T>*> order_;
        size_t position;
    };

    template <class T>
    class PostOrderTreeView{
    public:
        explicit PostOrderTreeView(Tree<T> *tree) :root_(tree){}

        PostOrderTreeIterator<T> begin(){
            return PostOrderTreeIterator<T>(root_);
        }
        PostOrderTreeIterator<T> end(){
            return PostOrderTreeIterator<T>(root_).JumpToEnd();
        }

    private:
        Tree<T> *root_;
    };

    template <class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree){
        return PostOrderTreeView<T>(tree);
    }
}


#endif //JIMP_EXERCISES_TREEITERATORS_H
