#include "tree.h"
#include <exception>
#include <functional>
#include <sstream>
#include <iostream>
#include <iomanip>

template <class T> Tree<T>::Tree() : head(nullptr) {}
template <class T> Tree<T>::Tree(const Tree& orig) { head = orig.head; }
template <class T> Tree<T>::~Tree(){}

template <class T> void Tree<T>::add(std::shared_ptr<T> figure)
{
    if(head != nullptr) add(figure, head);
    else head = std::shared_ptr<Node<T>>(new Node<T>(figure));
}

template <class T> void Tree<T>::add(std::shared_ptr<T> figure, std::shared_ptr<Node<T>> pNode)
{
    if(figure->area() == pNode->GetFigure()->area())
        std::cout << "ups" << std::endl;
    if (figure->area() < pNode->GetFigure()->area())
    {
        std::cout << "To left: " << std::endl;
        if (pNode->GetLeft() == nullptr)
            pNode->SetLeft(std::shared_ptr<Node<T>>(new Node<T>(figure)));
        else
            add(figure, pNode->GetLeft());
    }
    if (figure->area() > pNode->GetFigure()->area())
    {
        std::cout << "To right: " << std::endl;
        if (pNode->GetRight() == nullptr)
            pNode->SetRight(std::shared_ptr<Node<T>>(new Node<T>(figure)));
        else
            add(figure, pNode->GetRight());
    }
}

template <class T> void Tree<T>::del(std::shared_ptr<T> &figure)
{
    std::shared_ptr<Node<T>> pointer = head;
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
                head = child;
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

template <class T> bool Tree<T>::empty()
{
    return head==nullptr;
}

template <class T> size_t Tree<T>::size()
{
    size_t cnt = 0;
    for(auto iter : *this) ++cnt;
    return cnt;
}

template <class T> std::shared_ptr<T> Tree<T>::operator[](size_t i)
{
    if (i > size() - 1) throw std::invalid_argument("index greater then tree size");
    size_t j = 0;

    for (std::shared_ptr<T> it : * this)
    {
        if (j == i) return it;
        ++j;
    }
    return std::shared_ptr<T>(nullptr);
}

template <class T> void Tree<T>::sort()
{
    if (size() > 1)
    {
        size_t a = size() / 2;
        size_t i = 0;
        std::shared_ptr<T> middle = head->GetFigure();
        for (auto it : *this)
        {
            if (a == i)
            {
                middle = it;
                break;
            }
            ++i;
        }
        //std::shared_ptr<T> middle = (std::shared_ptr<T>&)this[a];


        Tree<T> _left, _right;
        for (auto iter : *this)
        {
            if ((*iter).area() < middle->area())
            {
                _left.add(iter);
            }
            if ((*iter).area() > middle->area())
            {
                _right.add(iter);
            }
        }
        _left.sort();
        _right.sort();

        this->head = std::shared_ptr<Node<T>>(new Node<T>(middle));
        this->head->SetLeft(_left.head);
        this->head->SetRight(_right.head);
    }
}

template<class T > std::future<void> Tree<T>::sort_in_background()
{
    std::packaged_task<void(void)> task(std::bind(std::mem_fn(&Tree<T>::sort_parallel), this));
    std::future<void> res = task.get_future();
    std::lock_guard<std::mutex> lock(mut);
    std::thread th(std::move(task));
    th.detach();
    return res;
}

template <class T> void Tree<T>::sort_parallel()
{
    if (size() > 1)
    {
        size_t a = size() / 2, i = 0;
        std::cout << a << std::endl;
        std::shared_ptr<T> middle = head->GetFigure();
        for (auto it : *this)
        {
            if (a == i)
            {
                middle = it;
                break;
            }
            ++i;
        }

        Tree<T> _left, _right;
        for (auto iter : *this)
        {
            if ((*iter).area() < middle->area())
            {
                _left.add(iter);
            }
            if ((*iter).area() > middle->area())
            {
                _right.add(iter);
            }
        }

        std::future<void> left_res = _left.sort_in_background();
        std::future<void> right_res =_right.sort_in_background();

        head = std::shared_ptr<Node<T>>(new Node<T>(middle));;
        left_res.get();
        head->SetLeft(_left.head);
        right_res.get();
        head->SetRight(_right.head);
    }
}


template <class T> Iterator<Node<T>,T> Tree<T>::begin()
{
    return Iterator<Node<T>,T>(head);
}

template <class T> Iterator<Node<T>,T> Tree<T>::end()
{
    return Iterator<Node<T>,T>(nullptr);
}

template <class T> std::ostream& operator<<(std::ostream& os, const Tree<T>& tree)
{
    std::shared_ptr<Node<T>> item = tree.head;
    os << "Tree out: " << std::endl;
    os << *(item);
    os << std::endl;
    return os;
}

template <class T> void Tree<T>::print()
{
    std::shared_ptr<Node<T>> item = head;
    std::cout << "Tree out: " << std::endl;
    item->print(0);
}

#include "figure.h"
template class Tree<Figure>;
template std::ostream& operator<<(std::ostream& os, const Tree<Figure>& tree);
