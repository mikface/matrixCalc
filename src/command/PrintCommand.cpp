//
// Created by Mikuláš on 9. 6. 2018.
//

#include <iostream>
#include "PrintCommand.h"

PrintCommand::PrintCommand(const std::vector<std::string> &tokens, const std::shared_ptr<Calculator> &calc)
        : Command(tokens, calc) {
    sanitize();
}

void PrintCommand::sanitize() {
    if (tokens.size() != 1) {
        return;
    }
    matrixID = tokens[0];

    valid = true;
}

void PrintCommand::perform() {
    std::shared_ptr<Matrix> found = calc->findMatrix(matrixID);
    if (found == nullptr) {
        std::cout << "No matrix with id '" << matrixID << "' was found in database." << std::endl << std::endl;
        return;
    }
    found->print();
    std::cout << std::endl;
}
