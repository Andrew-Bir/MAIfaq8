#include "queue.h"

template<class T> Queue<T>::Queue()
{
    _size = 0;
}

template<class T> void Queue<T>::push(const std::shared_ptr<T> item)
{
    std::shared_ptr<Item<T>> tmp = std::make_shared<Item<T>>(item);
    if (empty())
    {
        _front = tmp;
        _back = _front;
    }
    else
    {
        _back->setNext(tmp);
        _back = tmp;
    }
    ++_size;
}

template<class T> void Queue<T>::pop()
{
    if (!this->empty())
    {
        std::shared_ptr<Item<T>> tmp = _front;
        if (_front == _back)
            _front = _back = nullptr;
        else
            _front = tmp->getNext();
        //delete tmp;
        --_size;
    }
}

template<class T> std::shared_ptr<T> Queue<T>::front() { return _front->getValue(); }
template<class T> size_t Queue<T>::size() const { return _size; }
template<class T> bool Queue<T>::empty() const { return _size == 0; }

template<class T> Queue<T>::~Queue()
{
    while (!this->empty())
    {
        pop();
    }
}

template class Queue<void*>;
