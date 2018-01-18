#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cstdlib>
#include <iostream>

#include "figure.h"

class Triangle : public Figure {
public:
    Triangle();
    Triangle(std::istream &is);
    Triangle(size_t i,size_t j,size_t k);
    Triangle(const Triangle& orig);

    Triangle& operator ++ ();
    double square() const;
    void print() override;

    /*friend bool operator> (const Triangle& left, const Triangle& right);
    friend bool operator< (const Triangle& left, const Triangle& right);
    friend bool operator == (const Triangle& left, const Triangle & right);*/

    friend std::ostream& operator << (std::ostream& os, const Triangle& obj);
    friend std::istream& operator>>(std::istream& is, Triangle& obj);

    Triangle& operator = (const Triangle& right);

    virtual ~Triangle();
private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
};

#endif // TRIANGLE_H
