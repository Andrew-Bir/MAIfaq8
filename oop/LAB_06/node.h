#ifndef NODE_H
#define NODE_H

#include <memory>

template <class T> class Node {
public:
    Node(const std::shared_ptr<T> figure);
    template<class A> friend std::ostream& operator<<(std::ostream& os, const Node<A>& obj);

    std::shared_ptr<Node<T>> SetLeft(std::shared_ptr<Node<T>> ptr);
    std::shared_ptr<Node<T>> GetLeft();
    std::shared_ptr<Node<T>> SetRight(std::shared_ptr<Node<T>> ptr);
    std::shared_ptr<Node<T>> GetRight();
    std::shared_ptr<T> GetFigure() const;

    void * operator new (size_t size);
    void operator delete(void *p);

    virtual ~Node();
private:
    std::shared_ptr<T> figure;
    std::shared_ptr<Node<T>> pLeft;
    std::shared_ptr<Node<T>> pRight;
};

#endif // NODE_H
