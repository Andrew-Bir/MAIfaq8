#ifndef FIGURE_H
#define FIGURE_H

#include <cstdlib>
#include <iostream>
#include <memory>


class Figure
{
public:
    virtual ~Figure() {}
    virtual double area() const = 0;
    virtual void print() = 0;

};

#endif // FIGURE_H
