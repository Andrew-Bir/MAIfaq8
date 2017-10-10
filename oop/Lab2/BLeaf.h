#ifndef BTREEITEM_H_H
#define BTREEITEM_H_H

#include "triangle.h"
class BLeaf {
public:
    BLeaf(const Triangle& triangle);
    BLeaf(const BLeaf& orig);
    friend std::ostream& operator<<(std::ostream& os, const BLeaf& obj);

    BLeaf* GetRight();
    BLeaf* GetLeft();
    Triangle GetTriangle() const;

    virtual ~BLeaf();
private:
    Triangle triangle;
    BLeaf *right;
    BLeaf *left;
};

#endif /* BTREEITEM_H_H */

