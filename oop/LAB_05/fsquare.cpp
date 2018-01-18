#include <iostream>
#include <cmath>
#include "fsquare.h"

FSquare::FSquare() : FSquare(0) {
}

FSquare::FSquare(size_t i) : side_a(i) {
    std::cout << "Square created: " << side_a << std::endl;
}

FSquare::FSquare(std::istream& is) {
    is >> side_a;
}

FSquare::FSquare(const FSquare& orig) {
    std::cout << "Square copy created" << std::endl;
    side_a = orig.side_a;
}

double FSquare::square() const
{
    return (side_a * side_a);
}

void FSquare::print() {
    std::cout << "Figure(Square):  a=" << side_a << std::endl;

}

FSquare::~FSquare() {
    std::cout << "FSquare deleted" << std::endl;
}

inline std::ostream& operator << (std::ostream& os, const FSquare& obj)
{
    os << "a=" << obj.side_a;
    return os;
}

std::istream& operator>>(std::istream& is, FSquare& obj) {
    is >> obj.side_a;
    return is;
}

