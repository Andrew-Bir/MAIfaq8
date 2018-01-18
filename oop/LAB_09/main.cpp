#include <cstdlib>
#include <iostream>
#include <memory>
#include <future>
#include <thread>
#include <functional>
#include <random>
#include <string>

#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "node.h"
#include "tree.h"
#include "item.h"
#include "queue.h"

int main()
{
    Tree<Figure> tree;
    typedef std::function<void(void) > command;
    Queue<command> cmd;

    command cmd_insert = [&]()
    {
        std::cout << "Command: Create figure" << std::endl;

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distrFigureType(1, 3);
        std::uniform_int_distribution<int> distrFigureParam(1, 100);
        for (int i = 0; i < 20; ++i)
        {
            int side = distrFigureParam(generator);
            switch (distrFigureType(generator))
            {
            case 1:
            {
                tree.add(std::shared_ptr<Figure>(new Triangle(side,side,side)));
                break;
            }
            case 2:
            {
                tree.add(std::shared_ptr<Figure>(new Triangle(side,side,side)));
                break;

            }
            case 3:
            {
                tree.add(std::shared_ptr<Figure>(new Triangle(side,side,side)));
                break;
            }
            }
        }
    };

    command cmd_print = [&]()
    {
        std::cout << "Command: Print tree" << std::endl;
        tree.print();
    };

    command cmd_delete = [&]()
    {
        std::cout << "Command: Delete figure" << std::endl;
        std::uniform_int_distribution<double> distrArea(1.0, 1000.0);


    };

    cmd.push(std::shared_ptr<command> (&cmd_insert, [](command*) { }));
    cmd.push(std::shared_ptr<command> (&cmd_print, [](command*) { }));
    cmd.push(std::shared_ptr<command> (&cmd_delete, [](command*) { }));
    cmd.push(std::shared_ptr<command> (&cmd_print, [](command*) { }));

    while (!cmd.empty())
    {
        std::shared_ptr<command> _cmd = cmd.front();
        cmd.pop();
        std::future<void> ft = std::async(*_cmd);
        ft.get();
    }

    return 0;
}
