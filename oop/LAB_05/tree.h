#ifndef TREE_H
#define TREE_H

#include "figure.h"
#include "treenode.h"
#include "iterator.h"

#include <memory>

template <class T> class Tree {
public:
    Tree();
    Tree(std::shared_ptr<T> node);
    Tree(const Tree& orig);

    void add(std::shared_ptr<T> figure);
    void del(std::shared_ptr<T> &figure);
    bool empty();

    Iterator<TreeNode<T>,T> begin();
    Iterator<TreeNode<T>,T> end();

    template <class A> friend std::ostream& operator<<(std::ostream& os, const Tree<A>& tree);

    virtual ~Tree();

private:
    std::shared_ptr<TreeNode<T>> head;
    void add(std::shared_ptr<T> figure, std::shared_ptr<TreeNode<T>> pNode);
};

#endif // TREE_H
