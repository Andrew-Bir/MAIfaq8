﻿#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0, 0, 0)
{
    std::cout << "Triangle created: default" << std::endl;
}

Triangle::Triangle(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_c(k) {
    std::cout << "Triangle created: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

Triangle::Triangle(std::istream &is)
{
    is >> side_a;
    is >> side_b;
    is >> side_c;
}

Triangle::Triangle(const Triangle& orig) {
    std::cout << "Triangle copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_c = orig.side_c;
}

double Triangle::area() const
{
    double p = double(side_a + side_b + side_c) / 2.0;
    return std::sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));
}

void Triangle::print()
{
    std::cout << "Figure(Triangle): a=" << side_a << ", b=" << side_b << ", c=" << side_c << std::endl;
}

Triangle& Triangle::operator=(const Triangle& right) {

    if (this == &right) return *this;

    std::cout << "Triangle copied" << std::endl;
    side_a = right.side_a;
    side_b = right.side_b;
    side_c = right.side_c;

    return *this;
}

Triangle::~Triangle()
{
    std::cout << "Triangle deleted" << std::endl;
}

inline std::ostream& operator << (std::ostream& os, const Triangle& obj)
{
    os << "a=" << obj.side_a << ", b=" << obj.side_b << ", c=" << obj.side_c;
    return os;
}

std::istream& operator>>(std::istream& is, Triangle& obj) {
    is >> obj.side_a;
    is >> obj.side_b;
    is >> obj.side_c;
    return is;
}


