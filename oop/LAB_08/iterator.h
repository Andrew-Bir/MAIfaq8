#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>

template <class node, class T> class Iterator
{
public:
    Iterator(std::shared_ptr<node> ptr)
    {
        std::shared_ptr<node> root = ptr;
        while (root != nullptr)
        {
            _stack.push(root);
            root = root->GetLeft();
        }
        if (!_stack.empty())
        {
            _cur = _stack.top();
            _stack.pop();
        } else _cur = nullptr;
    }

    std::shared_ptr<T> operator*() { return _cur->GetFigure(); }
    std::shared_ptr<T> operator->() { return _cur->GetFigure(); }

    Iterator& operator ++ ()
    {
        if(_cur->GetRight() != nullptr)
        {
            _stack.push(_cur->GetRight());
            std::shared_ptr<node> tmp = _cur->GetRight()->GetLeft();
            if (tmp != nullptr) _stack.push(tmp);
        }
        if (_stack.empty())
        {
            _cur = nullptr;
            return *this;
        }
        _cur = _stack.top();
        _stack.pop();
        return *this;
    }

    Iterator& operator ++ (int)
    {
        Iterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator==(Iterator const& it) { return _cur == it._cur; }
    bool operator!=(Iterator const& it) { return !(*this == it); }

private:
    std::shared_ptr<node> _cur;
    // элемент стека
    template <class H> class _Node
    {
    public:
        _Node(std::shared_ptr<node> ptr)
        {
            this->_item = ptr;
            this->_next = nullptr;
        }

        ~_Node() {}

        std::shared_ptr<_Node<H>> SetNext(std::shared_ptr<_Node<H>> ptr)
        {
            std::shared_ptr<_Node<H>> old = this->_next;
            this->_next = ptr;
            return old;
        }

        std::shared_ptr<node> GetItem() const { return this->_item; }
        std::shared_ptr<_Node<H>> GetNext() { return this->_next; }

    private:
        std::shared_ptr<node> _item;
        std::shared_ptr<_Node<H>> _next;
    };
    // стек
    template <class H> class TStack
    {
    public:
        TStack() : _head(nullptr) {}
        ~TStack() {} // деструктор

        void push(std::shared_ptr<node> ptr)
        {
            std::shared_ptr<_Node<H>> newnode(new _Node<H>(ptr));
            newnode->SetNext(_head);
            _head = newnode;
        }
        void pop()
        {
            if (_head != nullptr)
            {
                std::shared_ptr<_Node<H>> tmp = _head;
                _head = tmp->GetNext();
                tmp.reset();
             }
         }
        bool empty() { return _head == nullptr; }

       std::shared_ptr<node> top() { return _head->GetItem(); }

    private:
        int _size; // размер стека
        std::shared_ptr<_Node<H>> _head; // вершина стека
    };
    TStack<node> _stack;
};

#endif // ITERATOR_H
