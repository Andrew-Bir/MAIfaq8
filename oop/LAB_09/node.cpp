#include "node.h"
#include <iostream>

template <class T> Node<T>::Node(const std::shared_ptr<T> figure)
{
    this->figure = figure;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    std::cout << "Tree node: created " << std::endl;
    //std::cout << this->figure << std::endl; потому что так оно не работает
    this->GetFigure()->print();
}

template <class T> Node<T>::~Node() { std::cout << "Tree node: deleted" << std::endl; }

template <class T> std::shared_ptr<Node<T>> Node<T>::SetLeft(std::shared_ptr<Node<T>> ptr)
{
    std::shared_ptr<Node<T>> old = this->pLeft;
    return this->pLeft = ptr;
    //return old;
}

template <class T> std::shared_ptr<Node<T>> Node<T>::SetRight(std::shared_ptr<Node<T>> ptr)
{
    std::shared_ptr<Node<T>> old = this->pRight;
    return this->pRight = ptr;
    //return old;
}

template <class T> std::shared_ptr<T> Node<T>::GetFigure() const { return this->figure; }

template <class T> std::shared_ptr<Node<T>> Node<T>::GetLeft() { return this->pLeft; }

template <class T> std::shared_ptr<Node<T>> Node<T>::GetRight() { return this->pRight; }

template <class T> std::ostream& operator<<(std::ostream& os, const Node<T>& obj)
{
    if (obj.pLeft!=nullptr) os << *obj.pLeft;
    //os << obj.figure << std::endl;
    obj.GetFigure()->print();
    if (obj.pRight!=nullptr) os << *obj.pRight;
    return os;
}

template <class T> void Node<T>::print(int level)
{
    if (this->pLeft!=nullptr) this->pLeft->print(level + 1);
    std::cout<<"|";
    for(int i = 0;i< level;i++) std::cout<<"___";
    std::shared_ptr<T> f = this->GetFigure();
    f->print();
    if (this->pRight!=nullptr) this->pRight->print(level + 1);
}

#include "figure.h"
template class Node<Figure>;
template std::ostream& operator<<(std::ostream& os, const Node<Figure> &obj);
