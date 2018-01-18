#ifndef Square_H
#define Square_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Square : public Figure{
public:
    Square();
    Square(std::istream& is);
    Square(size_t i);
    Square(const Square& orig);

    virtual ~Square();

    double area() const;
    void print() override;

    int type() {return 2;}

    friend std::ostream& operator << (std::ostream& os, const Square& obj);
    friend std::istream& operator>>(std::istream& is, Square& obj);

    Square& operator = (const Square& right);

private:
    size_t side_a;
};

#endif /* Square_H */

