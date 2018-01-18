#include "tree.h"

#include <exception>
#include <sstream>
#include <iostream>
#include <iomanip>

template <class T> Tree<T>::Tree() : head(nullptr) {}
template <class T> Tree<T>::Tree(const Tree& orig) { head = orig.head; }

template <class T> std::ostream& operator<<(std::ostream& os, const Tree<T>& tree)
{
    std::shared_ptr<Node<T>> item = tree.head;
    os << "Tree out: " << std::endl;
    os << *(item);
    os << std::endl;
    return os;
}

template <class T> void Tree<T>::add(std::shared_ptr<T> figure)
{
    if(head != nullptr)
        add(figure, head);
    else
        head = std::shared_ptr<Node<T>>(new Node<T>(figure));
}

template <class T> void Tree<T>::add(std::shared_ptr<T> figure, std::shared_ptr<Node<T>> pNode)
{
    if(figure->area() == pNode->GetFigure()->area())
        std::cout << "ups" << std::endl;
    if (figure->area() < pNode->GetFigure()->area())
    {
        std::cout << "left: " << std::endl;
        if (pNode->GetLeft() == nullptr)
            pNode->SetLeft(std::shared_ptr<Node<T>>(new Node<T>(figure)));
        else
            add(figure, pNode->GetLeft());
    }
    if (figure->area() > pNode->GetFigure()->area())
    {
        std::cout << "right: " << std::endl;
        if (pNode->GetRight() == nullptr)
            pNode->SetRight(std::shared_ptr<Node<T>>(new Node<T>(figure)));
        else
            add(figure, pNode->GetRight());
    }
}

template <class T> bool Tree<T>::empty() { return head == nullptr; }

template <class T> void Tree<T>::del(std::shared_ptr<T> &figure)
{
    std::shared_ptr<Node<T>> pointer = this->head;
    std::shared_ptr<Node<T>> parent  = nullptr;

    while (pointer!=nullptr && pointer->GetFigure()->area()!=figure->area())
    {
        parent = pointer;
        if (figure->area() < pointer->GetFigure()->area())
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
        std::shared_ptr<Node<T>> removed = nullptr;

        if (pointer->GetLeft() == nullptr || pointer->GetRight() == nullptr)
        {
            std::shared_ptr<Node<T>> child = nullptr;
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
            std::shared_ptr<Node<T>> mostLeft = pointer->GetRight();
            std::shared_ptr<Node<T>> mostLeftParent = pointer;

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

template <class T> void Tree<T>::print()
{
    std::shared_ptr<Node<T>> item = head;
    std::cout << "Tree out: " << std::endl;
    item->print(0);
}

template <class T> Iterator<Node<T>,T> Tree<T>::begin() { return Iterator<Node<T>,T>(head); }

template <class T> Iterator<Node<T>,T> Tree<T>::end() { return Iterator<Node<T>,T>(nullptr); }

template <class T> Tree<T>::~Tree(){}

#include "figure.h"
template class Tree<Figure>;
template std::ostream& operator<<(std::ostream& os, const Tree<Figure>& tree);
