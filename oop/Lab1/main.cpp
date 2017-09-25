#include <cstdlib>
#include "triangle.h"
#include "fsquare.h"
#include "rectangle.h"

using namespace std;

int menu()
{
    int variant;
    cout << "Enter your figure" << endl;
    cout << "1. Triangle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Square" << endl;
    cout << "4. Quit" << endl;
    cin >> variant;
    return variant;
    
}

int main(int argc, char** argv) 
{
    int type;
    do {
        type = menu();
        switch (type)
        {
            case 1:  
            {  
                std::cout << "Enter the value of a, b and c separated by space:"<< endl;
                Figure* ptr = new Triangle(cin); 
                ptr->Print();
                cout << ptr->Square() << endl;
                delete ptr;
                break;
            }
            case 2:
            {
                cout << "Enter the value of a and b separated by space:" << endl;
                Figure* ptr = new Rectangle(std::cin);
                ptr->Print();
                cout << ptr->Square() << endl;
                delete ptr;
                break;
            }
            case 3:
            {
                cout << "Enter the value of a:" << endl;
                Figure* ptr = new FSquare(cin);
                ptr->Print();
                cout << ptr->Square() << endl;
                delete ptr;
                break;
            }
            case 4: 
            {
                cout << "Quitting program" << endl;
                break;
            }
            default:
            {
                cout << "Error" << endl;
            }
        }
    } while (type != 4);
    return 0;
}

