#include "treenode.h"
#include <iostream>



template <class T> TreeNode<T>::TreeNode(const std::shared_ptr<T> figure) {
    this->figure = figure;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    std::cout << "Tree node: created " << std::endl;
    //std::cout << this->figure << std::endl;
    this->GetFigure()->print();
}

template <class T> TreeNode<T>::TreeNode(const TreeNode& orig) {
    this->figure = orig.figure;
    this->pLeft = orig.pLeft;
    this->pRight = orig.pRight;
    std::cout << "Tree node: copied" << std::endl;
}

template <class T> std::shared_ptr<TreeNode<T>> TreeNode<T>::SetLeft(std::shared_ptr<TreeNode<T>> ptr) {
    return this->pLeft = ptr;
}

template <class T> std::shared_ptr<TreeNode<T>> TreeNode<T>::SetRight(std::shared_ptr<TreeNode<T>> ptr) {
    return this->pRight = ptr;
}

template <class T> std::shared_ptr<T> TreeNode<T>::GetFigure() const {
    return this->figure;
}

template <class T> std::shared_ptr<TreeNode<T>> TreeNode<T>::GetLeft() {
    return this->pLeft;
}

template <class T> std::shared_ptr<TreeNode<T>> TreeNode<T>::GetRight() {
    return this->pRight;
}

template <class T> TreeNode<T>::~TreeNode() {
    std::cout << "Tree node: deleted" << std::endl;
    if(pLeft) {
        pLeft.reset();
        pLeft = nullptr;
    }
    if(pRight) {
        pRight.reset();
        pRight = nullptr;
    }
}

template <class T> std::ostream& operator<<(std::ostream& os, const TreeNode<T>& obj)
{
    if (obj.pLeft!=nullptr) os << *obj.pLeft;
    //os << obj.figure << std::endl;
    obj.GetFigure()->print();
    if (obj.pRight!=nullptr) os << *obj.pRight;
    return os;
}

#include "figure.h"
template class TreeNode<Figure>;
template std::ostream& operator<<(std::ostream &out, const TreeNode<Figure> &obj);
