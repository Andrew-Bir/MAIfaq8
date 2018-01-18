#ifndef TREE_H
#define TREE_H

#include "figure.h"
#include "node.h"
#include "iterator.h"

#include <memory>
#include <exception>
#include <future>
#include <mutex>
#include <thread>

template <class T> class Tree
{
public:
    Tree();
    Tree(std::shared_ptr<T> node);
    Tree(const Tree& orig);

    virtual ~Tree();

    void print();

    void add(std::shared_ptr<T> figure);
    void del(std::shared_ptr<T> &figure);
    bool empty();
    size_t size();

    std::shared_ptr<T> operator[] (size_t i);
    void sort();
    void sort_parallel();

    Iterator<Node<T>,T> begin();
    Iterator<Node<T>,T> end();

    template <class A> friend std::ostream& operator<<(std::ostream& os, const Tree<A>& tree);

private:
    std::shared_ptr<Node<T>> head;
    void add(std::shared_ptr<T> figure, std::shared_ptr<Node<T>> pNode);
    std::future<void> sort_in_background();
    mutable std::mutex mut;

};

#endif // TREE_H
