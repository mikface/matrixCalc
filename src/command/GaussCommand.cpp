//
// Created by Mikuláš on 11. 6. 2018.
//

#include "GaussCommand.h"
#include "../operation/Gauss.h"

GaussCommand::GaussCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator)
        : Command(commandTokens, calculator) {
    sanitize();
}

void GaussCommand::sanitize() {
    if (tokens.size() != 2) {
        return;
    }

    valid = true;
}

void GaussCommand::perform() {

    lhs = calc->findMatrix(tokens[0], true);

    if (lhs == nullptr) {
        return;
    }
    result = Gauss(lhs).perform();
    calc->saveMatrix(tokens[1], result);
}
