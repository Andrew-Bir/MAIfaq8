#include <cstdlib>
#include "triangle.h"
#include "TStackItem.h"
#include "TStack.h"

using namespace std;

int menu()
{
    int variant;
    cout << "Enter your action" << endl;
    cout << "1.Add Triangle to binary tree" << endl;
    cout << "2.Delete Triangle" << endl;
    cout << "3.Get Triangle" << endl;
    cout << "4.Print binary tree" << endl;
    cout << "5.Delete binary tree" << endl;
    cout << "6. Quit" << endl;
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
                cout << "Enter the value of a, b and c separated by space:"<< endl;
                Triangle *ptr_triangle = new Triangle();
                ptr_stack->push();
                delete ptr_triangle;
                break;
            }
            
            case 2:
            {
                ptr_stack->pop();
            }
            
            case 3:
            {
                cout << "meh" << endl;
            }
            
            case 4:
            {
                cout << ptr_stack;
            }
            
            case 5:
            {
                delete ptr_stack;
            }
            
            case 6: 
            {
                cout << "Quitting program" << endl;
                break;
            }
            
            default:
            {
                cerr << "Error" << endl; // cerr
            }
        }
    } while (type != 6);
    return 0;
}

