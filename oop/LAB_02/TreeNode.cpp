#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode(const Triangle& triangle) {
    this->triangle = triangle;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    std::cout << "Tree node: created " << std::endl;
    std::cout << this->triangle;
}

TreeNode::TreeNode(const TreeNode& orig) {
    this->triangle = orig.triangle;
    this->pLeft = orig.pLeft;
    this->pRight = orig.pRight;
    std::cout << "Tree node: copied" << std::endl;
}

TreeNode* TreeNode::SetLeft(TreeNode* ptr) {
    return this->pLeft = ptr;
}

TreeNode* TreeNode::SetRight(TreeNode* ptr) {
    return this->pRight = ptr;
}

Triangle TreeNode::GetTriangle() const {
    return this->triangle;
}

TreeNode* TreeNode::GetLeft() {
    return this->pLeft;
}

TreeNode* TreeNode::GetRight() {
    return this->pRight;
}

TreeNode::~TreeNode() {
    std::cout << "Tree node: deleted" << std::endl;
    if(pLeft) {
        delete pLeft; 
        pLeft = nullptr;
    }
    if(pRight) {
        delete pRight; 
        pRight = nullptr;
    }
}

std::ostream& operator<<(std::ostream& os, const TreeNode& obj) 
{
    if (obj.pLeft!=nullptr) os << *obj.pLeft;
    os << obj.triangle;
    if (obj.pRight!=nullptr) os << *obj.pRight;
    return os;
}

