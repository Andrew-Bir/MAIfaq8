#include "BTree.h"

BTree::BTree() : root(nullptr) {
}

BTree::BTree(const BTree& orig) {
    root = orig.root;
}



//???
std::ostream& operator<<(std::ostream& os, const BTree& tree) {

    BLeaf *item = tree.root;
    
    while(item!=nullptr)
    {
      os << *item;
      item = item->GetLeft();
    }
    
    return os;
}
//???
void BTree::insert(Triangle t, BLeaf *leaf) {
    
    if (t < (leaf->GetTriangle())) {
        
        if(leaf->GetLeft() != nullptr) {
            
            insert(t, leaf->GetLeft());
            
        }else { 
            leaf->GetLeft() = new BLeaf;
            leaf->GetLeft()->GetTriangle() = t;
            leaf->GetLeft()->GetLeft() = nullptr;
            leaf->GetLeft()->GetRight() = nullptr;
        }
   
    } else if(t>=leaf->GetTriangle()) {
        if(leaf->GetRight() != nullptr) {
            insert(t, leaf->GetRight());
        }else {
            leaf->GetRight() = new BLeaf;
            leaf->GetRight()->GetTriangle() = t;
            leaf->GetRight()->GetLeft() = nullptr;
            leaf->GetRight()->GetRight() = nullptr;
        }
    }
        
}

void BTree::insert(Triangle t)
{
    if(!empty()) {
        insert(t, root);
    } else {
        root = new BLeaf;
        root->GetTriangle() = t;
        root->GetLeft() = nullptr;
        root->GetRight() = nullptr;
    }
}

BLeaf *BTree::search(Triangle t, BLeaf* leaf)
{
    if(leaf != nullptr) {
        if(t == leaf->GetTriangle())
            return leaf;
        if(t< leaf->GetTriangle())
            return search(t, leaf->GetLeft());
        else
            return search(t, leaf->GetRight());
    } 
    else
        return nullptr;
}


void *BTree::search(Triangle t) {
    return search(t,root);
}

bool BTree::empty() {
    return root == nullptr;
}

void destroy_tree(BLeaf *leaf)
{
    if (leaf != nullptr) {
        destroy_tree(leaf->GetLeft());
        destroy_tree(leaf->GetRight());
        delete leaf;
    }
}

void BTree::destroy_tree() 
{
    destroy_tree(root);
}
/*BTree::~BTree() {
    
}*/

