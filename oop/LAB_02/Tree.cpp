#include "Tree.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Tree::Tree() : head(nullptr) {
} 

Tree::Tree(const Tree& orig) {
    head = orig.head;
}

std::ostream& operator<<(std::ostream& os, const Tree& tree) 
{
    TreeNode *item = tree.head;
    os << "Tree out: " << std::endl;
    os << *item;
    os << std::endl;    
    return os;
}

void Tree::add(Triangle triangle)
{
    if(head != nullptr) add(triangle, head);
    else head = new TreeNode(triangle);
}

void Tree::add(Triangle triangle, TreeNode* pNode) {
    if(triangle == pNode->GetTriangle()) {
        std::cout << "ups" << std::endl;
    }
    if (triangle < pNode->GetTriangle()) {
        std::cout << "left: " << std::endl;
        if (pNode->GetLeft() == nullptr) {
            pNode->SetLeft(new TreeNode(triangle));
        } else add(triangle, pNode->GetLeft());
    }
    if (triangle > pNode->GetTriangle()) {
        std::cout << "right: " << std::endl;
        if (pNode->GetRight() == nullptr) {
            pNode->SetRight(new TreeNode(triangle));
        } else add(triangle, pNode->GetRight());
    } 
}

bool Tree::empty() {
    return head == nullptr;
}

TreeNode* Tree::del(Triangle triangle) 
{
    if(this->head != nullptr) return this->del(this->head,triangle);
    else return this->head;
}

TreeNode* Tree::del(TreeNode* pNode, Triangle triangle) {
    TreeNode *t = new TreeNode(triangle);
    if (pNode == nullptr)
        return nullptr;
    if (triangle == pNode->GetTriangle()) {
        if (pNode->GetLeft() == nullptr) {
            t = pNode->GetRight();
            delete pNode;
            return t;
        }
        t = pNode->GetLeft();
        while (t->GetRight()) {
            t = t->GetRight();
        }
        t->SetRight(pNode->GetRight());
        return pNode->GetLeft();
    }
    if (triangle < pNode->GetTriangle()) {
        pNode->SetLeft(del(pNode->GetLeft(), triangle));
    } else {
        pNode->SetRight(del(pNode->GetRight(), triangle));
    }
    return pNode;
}

Tree::~Tree() {
    delete head;
}
