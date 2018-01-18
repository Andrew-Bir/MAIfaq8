#ifndef ITEM_H
#define ITEM_H

#include <memory>

template <class T> class Item
{
public:
    Item(const std::shared_ptr<T>& value);
    virtual ~Item();

    std::shared_ptr<Item<T>> getNext();
    std::shared_ptr<T> getValue();
    void setNext(std::shared_ptr<Item<T>> next);
    void setValue(std::shared_ptr<T> value);

private:
    std::shared_ptr<T> _value;
    std::shared_ptr<Item<T>> _next;
};

#endif // ITEM_H
