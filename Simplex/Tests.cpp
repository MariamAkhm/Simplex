#include <iostream>
#include "Tests.h"
#include "Simplex.h"
#include "SimplexOps.h"
#include "Stream.h"
namespace OptLib
{
    void test1()
    {
        Point<2> p1{ 1, 2 }, p2{ 3, 4 };

        std::cout << "Take point:"
            << "\np1 = " << p1
            << "\nand point:"
            << "\np2 = " << p2
            << "\nand ADD them together to get:"
            << "\nout = " << p1 + p2
            << "\n\n";
    }
    void test2()
    {
        Point<2> p1{ 1, 2 };
        std::cout << p1 + 4.7;
    }
    void test3()
    {
        Point<2> p1{ 1, 2 };
        std::cout << p1 - 4.7;
    }
}
