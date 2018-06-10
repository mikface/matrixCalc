//
// Created by Mikuláš on 15. 5. 2018.
//
#include <iostream>
#include "Help.h"

void Help::print() {
    std::cout << "Supported commands are:" << std::endl << std::endl;
    std::cout << "SCAN <new matrix name> <num rows> <num columns> [-v]" << std::endl;
    std::cout << "PRINT <matrix name>" << std::endl;
    std::cout << "CALC <new matrix name> = <matrix 1 name> <operation *+-> <matrix 2 name>" << std::endl;
    std::cout << "TRANSPOSE <matrix name> [<new matrix name>]" << std::endl;
    std::cout
            << "SPLIT <matrix name> <new matrix width> <new matrix height> <new matrix name> [(<starting row>,<starting col>)]"
            << std::endl;
    std::cout << "MERGE <matrix 1> <matrix 2>" << std::endl;
    std::cout << "GEM <matrix name>" << std::endl;
    std::cout << "EXIT" << std::endl << std::endl;
    std::cout << "Note: Matrix name can be any unique string" << std::endl << std::endl;
}

void Help::printWrongCommand() {
    std::cout << "Invalid command syntax, please try again. For details, type 'help'" << std::endl
              << std::endl;
}
