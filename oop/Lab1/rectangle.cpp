#include <iostream>
#include <cmath>
#include "rectangle.h"

Rectangle::Rectangle() : Rectangle(0, 0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
    std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Rectangle::Rectangle(std::istream& in) {
    in >> side_a;
    in >> side_b;
}

Rectangle::Rectangle(const Rectangle& orig) {
    std::cout << "Rectangle copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
}

double Rectangle::Square() {
    return (side_a * side_b);

}

void Rectangle::Print() {
    std::cout << "a=" << side_a << ", b=" << side_b << std::endl;

}

Rectangle::~Rectangle() {
    std::cout << "Rectangle deleted" << std::endl;
}

