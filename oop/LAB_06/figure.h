#ifndef FIGURE_H
#define FIGURE_H

#include <cstdlib>
#include <iostream>
#include <memory>

#include "allocator.h"

class Figure {
public:
    virtual ~Figure() {}
    virtual double area() const = 0;
    virtual void print() = 0;

    static Allocator allocator;

};

#endif // FIGURE_H
