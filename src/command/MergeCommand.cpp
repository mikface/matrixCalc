//
// Created by Mikuláš on 11. 6. 2018.
//

#include "MergeCommand.h"
#include "../operation/binary/Merge.h"

MergeCommand::MergeCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator)
        : Command(commandTokens, calculator) {
    sanitize();
}

void MergeCommand::sanitize() {
    if (tokens.size() != 4 || tokens[2] != "=>") {
        return;
    }

    valid = true;
}

void MergeCommand::perform() {
    lhs = calc->findMatrix(tokens[0], true);
    rhs = calc->findMatrix(tokens[1], true);

    if (lhs == nullptr || rhs == nullptr) {
        return;
    }
    result = Merge(lhs, rhs).perform();
    calc->saveMatrix(tokens[3], result);
}
