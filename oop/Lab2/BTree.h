#ifndef BTREE_H
#define BTREE_H


#include "triangle.h"
#include "BLeaf.h"

class BTree {
public:
    BTree();
    BTree(const BTree& orig);
    virtual ~BTree();
    
    void insert(Triangle t);
    bool empty();
    void *search(Triangle t);
    void destroy_tree();
    friend std::ostream& operator<<(std::ostream& os,const BTree& tree);
    BTree remove(Triangle t);
private:
    void destroy_tree(BLeaf *leaf);
    void insert(Triangle t, BLeaf *leaf);
    BLeaf *search(Triangle t, BLeaf *leaf);
    
    BLeaf *root;
};

#endif /* BTREE_H */

