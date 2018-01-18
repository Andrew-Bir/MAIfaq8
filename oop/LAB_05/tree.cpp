#include "tree.h"
#include <sstream>
#include <iostream>
#include <iomanip>


template <class T> Tree<T>::Tree() : head(nullptr) {
}


template <class T> Tree<T>::Tree(const Tree& orig) {
    head = orig.head;
}

template <class T> std::ostream& operator<<(std::ostream& os, const Tree<T>& tree)
{
    std::shared_ptr<TreeNode<T>> item = tree.head;
    os << "Tree out: " << std::endl;
    os << *(item);
    os << std::endl;
    return os;
}

template <class T> void Tree<T>::add(std::shared_ptr<T> figure)
{
    if(head != nullptr) add(figure, head);
    else head = std::shared_ptr<TreeNode<T>>(new TreeNode<T>(figure));
}

template <class T> void Tree<T>::add(std::shared_ptr<T> figure, std::shared_ptr<TreeNode<T>> pNode) {
    if(figure->square() == pNode->GetFigure()->square()) std::cout << "ups" << std::endl;
    if (figure->square() < pNode->GetFigure()->square()) {
        std::cout << "left: " << std::endl;
        if (pNode->GetLeft() == nullptr) {
            pNode->SetLeft(std::shared_ptr<TreeNode<T>>(new TreeNode<T>(figure)));
        } else add(figure, pNode->GetLeft());
    }
    if (figure->square() > pNode->GetFigure()->square()) {
        std::cout << "right: " << std::endl;
        if (pNode->GetRight() == nullptr) {
            pNode->SetRight(std::shared_ptr<TreeNode<T>>(new TreeNode<T>(figure)));
        } else add(figure, pNode->GetRight());
    }
}

template <class T> bool Tree<T>::empty() {
    return head == nullptr;
}

template <class T> void Tree<T>::del(std::shared_ptr<T> &figure)
{
    std::shared_ptr<TreeNode<T>> pointer = this->head;
    std::shared_ptr<TreeNode<T>> parent  = nullptr;

    while (pointer!=nullptr && pointer->GetFigure()->square()!=figure->square())
    {
        parent = pointer;
        if (figure->square() < pointer->GetFigure()->square())
            pointer = pointer->GetLeft();
        else
            pointer = pointer->GetRight();
    }

    if (pointer != nullptr)
    {
        std::cout << std::endl;
        std::cout << "We found it!..." << std::endl;
        pointer->GetFigure()->print();
        std::cout << std::endl;
        std::shared_ptr<TreeNode<T>> removed = nullptr;

        if (pointer->GetLeft() == nullptr || pointer->GetRight() == nullptr)
        {
            std::shared_ptr<TreeNode<T>> child = nullptr;
            removed = pointer;

            if (pointer->GetLeft() != nullptr)
                child = pointer->GetLeft();
            else if (pointer->GetRight() != nullptr)
                child = pointer->GetRight();

            if (parent == nullptr)
                this->head = child;
            else
            {
                if (parent->GetLeft() == pointer)
                    parent->SetLeft(child);
                else
                    parent->SetRight(child);
            }
        }
        else // (pointer->left != NULL && pointer->right != NULL)
        {
            std::shared_ptr<TreeNode<T>> mostLeft = pointer->GetRight();
            std::shared_ptr<TreeNode<T>> mostLeftParent = pointer;

            while (mostLeft->GetLeft()!=nullptr)
            {
                mostLeftParent = mostLeft;
                mostLeft = mostLeft->GetLeft();
            }

            removed = mostLeft;

            if (mostLeftParent->GetLeft() == mostLeft)
                mostLeftParent->SetLeft(nullptr);
            else
                mostLeftParent->SetRight(mostLeft->GetRight());
        }

        std::cout << "It removed..." << std::endl;
        removed->GetFigure()->print();
        removed.reset();
        std::cout << std::endl;
    }
}

template <class T> Iterator<TreeNode<T>,T> Tree<T>::begin()
{
    return Iterator<TreeNode<T>,T>(head);
}

template <class T> Iterator<TreeNode<T>,T> Tree<T>::end()
{
    return Iterator<TreeNode<T>,T>(nullptr);
}

template <class T> Tree<T>::~Tree(){}

#include "figure.h"
template class Tree<Figure>;
template std::ostream& operator<<(std::ostream& os, const Tree<Figure>& tree);
