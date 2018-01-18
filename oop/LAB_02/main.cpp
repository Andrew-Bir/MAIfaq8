#include <cstdlib>
#include <iostream>

#include "Triangle.h"
#include "TreeNode.h"
#include "Tree.h"

int menu(){
    int variant;
    std::cout << "Enter your choice: " << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Output" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cin >> variant;
    return variant;
}

int main(int argc, char** argv) {

    Tree tree;
    int action;
    do {
        action = menu();
        switch (action)
        {
            case 1:  
            {
                std::cout << "Enter Enter the value of a, b and c separated by space:" << std::endl;
                Triangle a;
                std::cin >> a;
                tree.add(a);
                break;
            }
            case 2:
            {
                std::cout << "Enter Enter the value of a, b and c separated by space:" << std::endl;
                Triangle b;
                std::cin >> b;
                tree.del(b);
                break;
            }
            case 3: 
            {
                std::cout << tree;
                break;
            }
            case 4: 
            {
                std::cout << "Quitting program" << std::endl;
                break;
            }
            default:
            {
                std::cout << "Error" << std::endl;
            }
        }
    } while (action != 4);
    return 0;
}
