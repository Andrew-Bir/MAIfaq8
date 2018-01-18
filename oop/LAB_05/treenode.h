#ifndef TREENODE_H
#define TREENODE_H

#include <memory>

template <class T> class TreeNode {
public:
    TreeNode(const std::shared_ptr<T> figure);
    template<class A> friend std::ostream& operator<<(std::ostream& os, const TreeNode<A>& obj);

    std::shared_ptr<TreeNode<T>> SetLeft(std::shared_ptr<TreeNode<T>> ptr);
    std::shared_ptr<TreeNode<T>> GetLeft();
    std::shared_ptr<TreeNode<T>> SetRight(std::shared_ptr<TreeNode<T>> ptr);
    std::shared_ptr<TreeNode<T>> GetRight();
    std::shared_ptr<T> GetFigure() const;

    void * operator new (size_t size);
    void operator delete(void *p);

    virtual ~TreeNode();
private:
    std::shared_ptr<T> figure;
    std::shared_ptr<TreeNode<T>> pLeft;
    std::shared_ptr<TreeNode<T>> pRight;
};

#endif // TREENODE_H
