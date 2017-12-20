#ifndef TREENODE_H
#define TREENODE_H

#include "figure.h"
#include <memory>

class TreeNode {
public:
    TreeNode(const std::shared_ptr<Figure> figure);
    TreeNode(const TreeNode& orig);
    friend std::ostream& operator<<(std::ostream& os, const TreeNode& obj);

    std::shared_ptr<TreeNode> SetLeft(std::shared_ptr<TreeNode> ptr);
    std::shared_ptr<TreeNode> GetLeft();
    std::shared_ptr<TreeNode> SetRight(std::shared_ptr<TreeNode> ptr);
    std::shared_ptr<TreeNode> GetRight();
    std::shared_ptr<Figure> GetFigure() const;

    virtual ~TreeNode();
private:
    std::shared_ptr<Figure> figure;
    std::shared_ptr<TreeNode> pLeft;
    std::shared_ptr<TreeNode> pRight;
};

#endif // TREENODE_H
