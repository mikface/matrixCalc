//
// Created by Mikuláš on 11. 6. 2018.
//

#include <iostream>
#include "DeterminantCommand.h"

DeterminantCommand::DeterminantCommand(const std::vector<std::string> &commandTokens,
                                       const std::shared_ptr<Calculator> &calculator) : Command(commandTokens,
                                                                                                calculator) {
    sanitize();
}

void DeterminantCommand::sanitize() {
    if (tokens.size() != 1) {
        return;
    }

    valid = true;
}

void DeterminantCommand::perform() {
    matrix = calc->findMatrix(tokens[0], true);
    if (matrix == nullptr) {
        return;
    }
    try {
        det = matrix->getDeterminant();
    } catch (std::exception e) {
        std::cout << "Not a square Matrix" << std::endl << std::endl;
        return;
    }
    std::cout << "Determinant for Matrix with id: " << tokens[0] << " = " << det << std::endl
              << std::endl;
}
