#include <iostream>
#include <cmath>
#include "rectangle.h"

Rectangle::Rectangle() : Rectangle(0, 0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
    std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Rectangle::Rectangle(std::istream& is) {
    is >> side_a;
    is >> side_b;
}

Rectangle::Rectangle(const Rectangle& orig) {
    std::cout << "Rectangle copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
}

double Rectangle::area() const
{
    return (side_a * side_b);
}

void Rectangle::print() {
    std::cout << "Figure(Rectangle): a=" << side_a << ", b=" << side_b << std::endl;

}

void *Rectangle::operator new(size_t size) {
    std::cout << "Allocated: " << size << " bytes" << std::endl;
    return allocator.allocate();
}

void Rectangle::operator delete(void *p) {
    std::cout << "Deleted" << std::endl;
    allocator.deallocate(p);
}

Rectangle::~Rectangle() {
    std::cout << "Rectangle deleted" << std::endl;
}

inline std::ostream& operator << (std::ostream& os, const Rectangle& obj)
{
    os << "a=" << obj.side_a << ", b=" << obj.side_b;
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
    is >> obj.side_a;
    is >> obj.side_b;
    return is;
}

