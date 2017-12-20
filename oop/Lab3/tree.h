#ifndef TREE_H
#define TREE_H

#include "figure.h"
#include "treenode.h"
#include <memory>

class Tree {
public:
    Tree();
    Tree(TreeNode* node);
    Tree(const Tree& orig);

    void add(std::shared_ptr<Figure> figure);
    void del(std::shared_ptr<Figure> &figure);
    bool empty();
    friend std::ostream& operator<<(std::ostream& os, const Tree& tree);

    virtual ~Tree();

private:
    std::shared_ptr<TreeNode> head;
    void add(std::shared_ptr<Figure> figure, std::shared_ptr<TreeNode> pNode);
};

#endif // TREE_H
