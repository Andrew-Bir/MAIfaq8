#include <cstdlib>
#include <iostream>
#include <memory>

#include "figure.h"
#include "triangle.h"
#include "fsquare.h"
#include "rectangle.h"
#include "treenode.h"
#include "tree.h"

int menu(){
    /*
     * 1 add
     * 2 delete
     * 3 output
     */

    int variant;
    std::cout << "Enter your choice: " << std::endl;
    std::cout << "1. Add Triangle" << std::endl;
    std::cout << "2. Delete Triangle" << std::endl;
    std::cout << "3. Add Square" << std::endl;
    std::cout << "4. Delete Square" << std::endl;
    std::cout << "5. Add Rectangle" << std::endl;
    std::cout << "6. Delete Rectangle" << std::endl;
    std::cout << "7. Output" << std::endl;
    std::cout << "8. Quit" << std::endl;
    std::cin >> variant;
    return variant;

}

int main() {

    Tree tree;
    int action;
    do {
        action = menu();
        switch (action)
        {
            case 1:
            {
                std::cout << "Enter the value of a, b and c separated by space:" << std::endl;
                tree.add(std::shared_ptr<Figure>(new Triangle(std::cin)));
                break;
            }
            case 2:
            {
                std::cout << "Enter the value of a, b and c separated by space:" << std::endl;
                std::shared_ptr<Figure> b(new Triangle(std::cin));
                tree.del(b);
                break;
            }
            case 3:
            {
                std::cout << "Enter the value of a:" << std::endl;
                tree.add(std::shared_ptr<Figure>(new FSquare(std::cin)));
                break;
            }
        case 4:
        {
            std::cout << "Enter the value of a:" << std::endl;
            std::shared_ptr<Figure> b(new FSquare(std::cin));
            tree.del(b);
            break;
        }
            case 5:
            {
                std::cout << "Enter the value of a and b separated by space:" << std::endl;
                tree.add(std::shared_ptr<Figure>(new Rectangle(std::cin)));
                break;
            }
        case 6:
        {
            std::cout << "Enter the value of a and b separated by space:" << std::endl;
            std::shared_ptr<Figure> b(new Rectangle(std::cin));
            tree.del(b);
            break;
        }
            case 7:
            {
                std::cout << tree;
                break;
            }
            case 8:
            {
                std::cout << "Quitting program" << std::endl;
                tree.~Tree();
                std::cout << "Tree deleted" << std::endl;
                break;
            }
            default:
            {
                std::cout << "Error" << std::endl;
            }
        }
    } while (action != 8);
    return 0;
}
