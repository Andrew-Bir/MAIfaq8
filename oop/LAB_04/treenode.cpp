#include "treenode.h"
#include <iostream>

TreeNode::TreeNode(const std::shared_ptr<Figure> figure) {
    this->figure = figure;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    std::cout << "Tree node: created " << std::endl;
    //std::cout << this->figure << std::endl;
    this->GetFigure()->print();
}

TreeNode::TreeNode(const TreeNode& orig) {
    this->figure = orig.figure;
    this->pLeft = orig.pLeft;
    this->pRight = orig.pRight;
    std::cout << "Tree node: copied" << std::endl;
}

std::shared_ptr<TreeNode> TreeNode::SetLeft(std::shared_ptr<TreeNode> ptr) {
    return this->pLeft = ptr;
}

std::shared_ptr<TreeNode> TreeNode::SetRight(std::shared_ptr<TreeNode> ptr) {
    return this->pRight = ptr;
}

std::shared_ptr<Figure> TreeNode::GetFigure() const {
    return this->figure;
}

std::shared_ptr<TreeNode> TreeNode::GetLeft() {
    return this->pLeft;
}

std::shared_ptr<TreeNode> TreeNode::GetRight() {
    return this->pRight;
}

TreeNode::~TreeNode() {
    std::cout << "Tree node: deleted" << std::endl;
    if(pLeft) {
        pLeft.reset();
        pLeft = nullptr;
    }
    if(pRight) {
        pRight.reset();
        pRight = nullptr;
    }
}

std::ostream& operator<<(std::ostream& os, const TreeNode& obj)
{
    if (obj.pLeft!=nullptr) os << *obj.pLeft;
    //os << obj.figure << std::endl;
    obj.GetFigure()->print();
    if (obj.pRight!=nullptr) os << *obj.pRight;
    return os;
}

