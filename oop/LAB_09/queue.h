#ifndef QUEUE_H
#define QUEUE_H

#include "item.h"

#include <memory>
#include <future>
#include <mutex>
#include <thread>
#include <functional>

template <class T>
class Queue
{
public:
    Queue();
    virtual ~Queue();

    void push(const std::shared_ptr<T> item); //вставляет элемент в конец
    void pop(); //удаляет первый элемент
    std::shared_ptr<T> front(); //получение первого элемента
    bool empty() const; //Проверяет отсутствие элементов в контейнере
    size_t size() const; //Возвращает количество элементов в контейнере

    template <class H> friend std::ostream& operator << (std::ostream& os, const Queue<H> &queue);

private:
    std::shared_ptr<Item<T>> _front; //Предоставляет доступ к первому элементу
    std::shared_ptr<Item<T>> _back; //Предоставляет доступ к последнему элементу
    size_t _size;
    mutable std::mutex mut;
};

#endif // QUEUE_H
