#include <iostream>
#include <memory>

#include "item.h"

template <class T> Item<T>::Item(const std::shared_ptr<T>& value)
{
    _value = value;
    _next = nullptr;
}

template <class T> void Item<T>::setNext(std::shared_ptr<Item<T>> item) { _next = item; }
template <class T> std::shared_ptr<Item<T>> Item<T>::getNext() { return _next; }
template <class T> std::shared_ptr<T> Item<T>::getValue() { return _value;}
template <class T> Item<T>::~Item() {}

template class Item<void*>;
