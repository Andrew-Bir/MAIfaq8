#ifndef FSQUARE_H
#define FSQUARE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class FSquare : public Figure{
public:
    FSquare();
    FSquare(std::istream& input);
    FSquare(size_t i);
    FSquare(const FSquare& orig);

    double Square() override;
    void   Print() override;

    virtual ~FSquare();
private:
    size_t side_a;
};


#endif /* FSQUARE_H */

