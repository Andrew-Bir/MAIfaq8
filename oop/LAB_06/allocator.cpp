#include "allocator.h"

Allocator::Allocator(size_t size, size_t count) : _size(size),_count(count)
{
    _used = (unsigned char*)malloc(_size * _count);

    for(size_t i = 0; i  < _count; ++i)
    {
        void* tmp = (void *)malloc(sizeof(void *));
        tmp = _used + i * _size;
        _free.push(std::make_shared<void*>(tmp));
    }
    std::cout << "Allocator: Memory init" << std::endl;
}

void* Allocator::allocate()
{
    std::shared_ptr<void*> result = nullptr;
    if(!_free.empty())
    {
        result = _free.front();
        _free.pop();
        std::cout << "Allocator: Allocate " << (_count - _free.size()) << " of " << _count << std::endl;
    }
        else
    {
        std::cout << "Allocator: No memory exception" << std::endl;
        throw 1;
    }
    return *result;
}

void Allocator::deallocate(void* pt) {
  std::cout << "Allocator: Deallocate block "<< std::endl;
  _free.push(std::make_shared<void*>(pt));
}

bool Allocator::hasfreeblocks() const { return _free.size() > 0; }

Allocator::~Allocator()
{
    if(_free.size() < _count)
        std::cout << "Allocator: Memory leak?" << std::endl;
    else  std::cout << "Allocator: Memory freed" << std::endl;
    free(_used);
    //delete _free;
}

