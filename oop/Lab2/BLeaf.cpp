#include "BLeaf.h"
#include <iostream>

BLeaf::BLeaf(const Triangle& triangle) {
    this->triangle = triangle;
    this->right = nullptr;
    this->left = nullptr;
    std::cout << "Stack item: created" << std::endl;
}

BLeaf::BLeaf(const BLeaf& orig) {
    this->triangle = orig.triangle;
    this->right = orig.right;
    this->left = orig.left;
    std::cout << "Stack item: copied" << std::endl;
}


Triangle BLeaf::GetTriangle() const {
    return this->triangle;
}

BLeaf* BLeaf::GetRight() {
    return this->right;
}

BLeaf* BLeaf::GetLeft() {
    return this->left;
}

BLeaf::~BLeaf() {
    std::cout << "Binary tree item: deleted" << std::endl;
    delete right;
    delete left;

}

std::ostream& operator<<(std::ostream& os, const BLeaf& leaf) {
    os << "[" << leaf.triangle << "]" << std::endl;
    return os;
}

