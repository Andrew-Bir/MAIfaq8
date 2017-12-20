#include "tree.h"
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
    std::shared_ptr<TreeNode> item = tree.head;
    os << "Tree out: " << std::endl;
    os << *(item);
    os << std::endl;
    return os;
}

void Tree::add(std::shared_ptr<Figure> figure)
{
    if(head != nullptr) add(figure, head);
    else head = std::shared_ptr<TreeNode>(new TreeNode(figure));
}

void Tree::add(std::shared_ptr<Figure> figure, std::shared_ptr<TreeNode> pNode) {
    if(figure->square() == pNode->GetFigure()->square()) std::cout << "ups" << std::endl;
    if (figure->square() < pNode->GetFigure()->square()) {
        std::cout << "left: " << std::endl;
        if (pNode->GetLeft() == nullptr) {
            pNode->SetLeft(std::shared_ptr<TreeNode>(new TreeNode(figure)));
        } else add(figure, pNode->GetLeft());
    }
    if (figure->square() > pNode->GetFigure()->square()) {
        std::cout << "right: " << std::endl;
        if (pNode->GetRight() == nullptr) {
            pNode->SetRight(std::shared_ptr<TreeNode>(new TreeNode(figure)));
        } else add(figure, pNode->GetRight());
    }
}

bool Tree::empty() {
    return head == nullptr;
}

void Tree::del(std::shared_ptr<Figure> &figure)
{
    std::shared_ptr<TreeNode> pointer = this->head;
    std::shared_ptr<TreeNode> parent  = nullptr;

    while (pointer!=nullptr && pointer->GetFigure()->square()!=figure->square())
    {
        parent = pointer;
        if (figure->square() < pointer->GetFigure()->square())
            pointer = pointer->GetLeft();
        else
            pointer = pointer->GetRight();
    }

    if (pointer != nullptr)
    {
        std::cout << std::endl;
        std::cout << "We found it!..." << std::endl;
        pointer->GetFigure()->print();
        std::cout << std::endl;
        std::shared_ptr<TreeNode> removed = nullptr;

        if (pointer->GetLeft() == nullptr || pointer->GetRight() == nullptr)
        {
            std::shared_ptr<TreeNode> child = nullptr;
            removed = pointer;

            if (pointer->GetLeft() != nullptr)
                child = pointer->GetLeft();
            else if (pointer->GetRight() != nullptr)
                child = pointer->GetRight();

            if (parent == nullptr)
                this->head = child;
            else
            {
                if (parent->GetLeft() == pointer)
                    parent->SetLeft(child);
                else
                    parent->SetRight(child);
            }
        }
        else // (pointer->left != NULL && pointer->right != NULL)
        {
            std::shared_ptr<TreeNode> mostLeft = pointer->GetRight();
            std::shared_ptr<TreeNode> mostLeftParent = pointer;

            while (mostLeft->GetLeft()!=nullptr)
            {
                mostLeftParent = mostLeft;
                mostLeft = mostLeft->GetLeft();
            }

            removed = mostLeft;

            if (mostLeftParent->GetLeft() == mostLeft)
                mostLeftParent->SetLeft(nullptr);
            else
                mostLeftParent->SetRight(mostLeft->GetRight());
        }

        std::cout << "It removed..." << std::endl;
        removed->GetFigure()->print();
        removed.reset();
        std::cout << std::endl;
    }
}

Tree::~Tree()
{

}
