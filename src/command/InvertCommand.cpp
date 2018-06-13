//
// Created by Mikuláš on 13. 6. 2018.
//

#include <iostream>
#include "InvertCommand.h"
#include "../operation/Invert.h"

InvertCommand::InvertCommand(const std::vector<std::string> &commandTokens,
                             const std::shared_ptr<Calculator> &calculator) : Command(commandTokens,
                                                                                      calculator) {
    sanitize();
}

void InvertCommand::sanitize() {
    if (tokens.size() < 1 || tokens.size() > 2) {
        return;
    }

    saveAsNew = (tokens.size() == 2);
    valid = true;
}

void InvertCommand::perform() {
    lhs = calc->findMatrix(tokens[0], true);
    if (lhs == nullptr) {
        return;
    }
    if (lhs->getRows() != lhs->getColumns()) {
        std::cout << "Not a square matrix" << std::endl;
        return;
    }
    result = Invert(lhs).perform();
    if (saveAsNew) {
        calc->saveMatrix(tokens[1], result);
    } else {
        calc->deleteMatrix(tokens[0], true);
        calc->saveMatrix(tokens[0], result);
    }

}