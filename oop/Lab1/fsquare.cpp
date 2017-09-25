#include <iostream>
#include <cmath>
#include "fsquare.h"

FSquare::FSquare() : FSquare(0) {
}

FSquare::FSquare(size_t i) : side_a(i) {
    std::cout << "Square created: " << side_a << std::endl;
}

FSquare::FSquare(std::istream& input) {
    input >> side_a;
}

FSquare::FSquare(const FSquare& orig) {
    std::cout << "Square copy created" << std::endl;
    side_a = orig.side_a;
}

double FSquare::Square() {
    return (side_a * side_a);

}

void FSquare::Print() {
    std::cout << "a=" << side_a << std::endl;

}

FSquare::~FSquare() {
    std::cout << "FSquare deleted" << std::endl;
}

