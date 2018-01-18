#ifndef FIGURE_H
#define FIGURE_H

#include <cstdlib>
#include <iostream>
#include <memory>

class Figure {
public:
    virtual double square() const = 0;
    virtual void print() = 0;

    virtual ~Figure() {}
};

#endif // FIGURE_H
