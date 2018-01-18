#ifndef TREENODE_H
#define TREENODE_H

#include "Triangle.h"
class TreeNode {
public:
    TreeNode(const Triangle& triangle);
    TreeNode(const TreeNode& orig);
    friend std::ostream& operator<<(std::ostream& os, const TreeNode& obj);
    
    TreeNode* SetLeft(TreeNode* ptr);
    TreeNode* GetLeft();
    TreeNode* SetRight(TreeNode* ptr);
    TreeNode* GetRight();
    Triangle GetTriangle() const;

    virtual ~TreeNode();
private:
    Triangle triangle;
    TreeNode *pLeft;
    TreeNode *pRight;
};

#endif // TREENODE_H

