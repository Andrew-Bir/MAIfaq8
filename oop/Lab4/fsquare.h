#ifndef FSQUARE_H
#define FSQUARE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class FSquare : public Figure{
public:
    FSquare();
    FSquare(std::istream& is);
    FSquare(size_t i);
    FSquare(const FSquare& orig);

    double square() const;
    void print() override;

    friend std::ostream& operator << (std::ostream& os, const FSquare& obj);
    friend std::istream& operator>>(std::istream& is, FSquare& obj);

    FSquare& operator = (const FSquare& right);

    virtual ~FSquare();

private:
    size_t side_a;
};


#endif /* FSQUARE_H */

