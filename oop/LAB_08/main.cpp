#include <cstdlib>
#include <iostream>
#include <memory>

#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "node.h"
#include "tree.h"

int menu(){
    int variant;
    std::cout << "Enter your choice: " << std::endl;
    std::cout << "1. Add Triangle" << std::endl;
    std::cout << "2. Delete Triangle" << std::endl;
    std::cout << "3. Add Square" << std::endl;
    std::cout << "4. Delete Square" << std::endl;
    std::cout << "5. Add Rectangle" << std::endl;
    std::cout << "6. Delete Rectangle" << std::endl;
    std::cout << "7. Output" << std::endl;
    std::cout << "8. Sort" << std::endl;
    std::cout << "0. Quit" << std::endl;
    std::cin >> variant;
    return variant;
}

int main()
{

    Tree<Figure> tree;
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
            tree.add(std::shared_ptr<Figure>(new Square(std::cin)));
            break;
        }
        case 4:
        {
            std::cout << "Enter the value of a:" << std::endl;
            std::shared_ptr<Figure> b(new Square(std::cin));
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
            //std::cout << "Tree output:" << std::endl;
            //for (auto it : tree) it->GetFigure()->print();
            tree.print();
            //std::cout << tree;
            break;
        }
        case 8:
        {
            std::cout << "Tree sort:" << std::endl;
            //for (auto it : tree) it->GetFigure()->print();
            tree.sort();
            //std::cout << tree;
            break;
        }
        case 0:
        {
            std::cout << "Quitting program" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Error" << std::endl;
        }
        }
    } while (action != 0);

    return 0;
}
