//
// Created by Mikuláš on 15. 5. 2018.
//
#include <iostream>
#include "Help.h"

void Help::print() {
    std::cout << "Supported commands are:" << std::endl << std::endl;
    std::cout << "SCAN <new matrix name> <num rows> <num columns>" << std::endl;
    std::cout << "CALC <new matrix name> = <operation +-* with matrices in database>" << std::endl;
    std::cout
            << "SPLIT <matrix name> <new matrix width> <new matrix height> [(<starting row>,<starting col>)] <new matrix name>"
            << std::endl;
    std::cout << "MERGE <matrix 1> <matrix 2>" << std::endl;
    std::cout << "GEM <matrix name>" << std::endl << std::endl;
    std::cout << "Note: Matrix name can be any unique string" << std::endl << std::endl;
}