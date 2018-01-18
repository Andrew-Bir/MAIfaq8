#ifndef TREE_H
#define TREE_H

#include "figure.h"
#include "node.h"
#include "iterator.h"

#include <memory>
#include <future>
#include <mutex>
#include <thread>

template <class T> class Tree {
public:
    Tree();
    Tree(std::shared_ptr<T> node);
    Tree(const Tree& orig);

    void add(std::shared_ptr<T> figure);
    void del(std::shared_ptr<T> &figure);
    bool empty();

    void print();

    Iterator<Node<T>,T> begin();
    Iterator<Node<T>,T> end();

    template <class A> friend std::ostream& operator<<(std::ostream& os, const Tree<A>& tree);

    virtual ~Tree();

private:
    std::shared_ptr<Node<T>> head;
    void add(std::shared_ptr<T> figure, std::shared_ptr<Node<T>> pNode);

};

#endif // TREE_H
