#ifndef FIGURE_H
#define FIGURE_H

#include <cstdlib>
#include <iostream>
#include <memory>

class Figure {
public:
    virtual double square() const = 0;
    virtual void print() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure&);
    //friend std::istream& operator>>(std::istream& is, Figure& obj);

    virtual ~Figure() {}
};

#endif // FIGURE_H
