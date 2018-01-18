#include <iostream>
#include <cmath>
#include "square.h"

Square::Square() : Square(0) {}

Square::Square(size_t i) : side_a(i)
{
    std::cout << "Square created: " << side_a << std::endl;
}

Square::Square(std::istream& is)
{
    is >> side_a;
}

Square::Square(const Square& orig)
{
    std::cout << "Square copy created" << std::endl;
    side_a = orig.side_a;
}

double Square::area() const
{
    return (side_a * side_a);
}

void Square::print()
{
    std::cout << "Figure(Square):  a=" << side_a << std::endl;
}

Square::~Square()
{
    std::cout << "Square deleted" << std::endl;
}

inline std::ostream& operator << (std::ostream& os, const Square& obj)
{
    os << "a=" << obj.side_a;
    return os;
}

std::istream& operator>>(std::istream& is, Square& obj)
{
    is >> obj.side_a;
    return is;
}



