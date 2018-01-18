#ifndef TREE_H
#define TREE_H

#include "Triangle.h"
#include "TreeNode.h"

class Tree {
public:
    Tree();
    Tree(TreeNode* node);
    Tree(const Tree& orig);
    
    void add(Triangle triangle);
    TreeNode* del(Triangle triangle);
    bool empty();
    friend std::ostream& operator<<(std::ostream& os, const Tree& tree);
    
    virtual ~Tree();

private:
    TreeNode * head;
    void add(Triangle triangle, TreeNode* pNode);
    TreeNode* del(TreeNode* pNode, Triangle triangle);
 };

#endif // TREE_H

