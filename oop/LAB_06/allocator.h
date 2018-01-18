#ifndef ALLOC_H
#define ALLOC_H

#include <cstdlib>
#include <iostream>
#include "queue.h"

class Allocator
{
public:
    Allocator(size_t size, size_t count);
    ~Allocator();

    void* allocate();
    void deallocate(void* pt);
    bool hasfreeblocks() const;

private:
    size_t _size;
    size_t _count;

    unsigned char* _used;
    Queue<void*> _free; //для хранения списка свободных блоков
};

#endif // ALLOC_H
