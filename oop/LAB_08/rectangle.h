#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Rectangle : public Figure{
public:
    Rectangle();
    Rectangle(std::istream& is);
    Rectangle(size_t i, size_t j);
    Rectangle(const Rectangle& orig);

    virtual ~Rectangle();

    double area() const;
    void print() override;

    friend std::ostream& operator << (std::ostream& os, const Rectangle& obj);
    friend std::istream& operator>>(std::istream& is, Rectangle& obj);

    Rectangle& operator = (const Rectangle& right);

private:
    size_t side_a;
    size_t side_b;
};


#endif /* RECTANGLE_H */

