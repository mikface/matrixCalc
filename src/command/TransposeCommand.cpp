//
// Created by Mikuláš on 11. 6. 2018.
//

#include "TransposeCommand.h"
#include "../operation/Transpose.h"

TransposeCommand::TransposeCommand(const std::vector<std::string> &commandTokens,
                                   const std::shared_ptr<Calculator> &calculator) : Command(commandTokens,
                                                                                            calculator) {
    sanitize();
}

void TransposeCommand::sanitize() {
    if (tokens.size() < 1 || tokens.size() > 2) {
        return;
    }

    saveAsNew = (tokens.size() == 2);
    valid = true;
}

void TransposeCommand::perform() {
    lhs = calc->findMatrix(tokens[0], true);
    if (lhs == nullptr) {
        return;
    }
    result = Transpose(lhs).perform();
    if (saveAsNew) {
        calc->saveMatrix(tokens[1], result);
    } else {
        calc->deleteMatrix(tokens[0], true);
        calc->saveMatrix(tokens[0], result);
    }

}
