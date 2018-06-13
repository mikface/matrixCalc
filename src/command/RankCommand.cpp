//
// Created by Mikuláš on 13. 6. 2018.
//
#include <iostream>
#include "RankCommand.h"

RankCommand::RankCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator)
        : Command(commandTokens, calculator) {
    sanitize();
}

void RankCommand::sanitize() {
    if (tokens.size() != 1) {
        return;
    }

    valid = true;
}

void RankCommand::perform() {
    matrix = calc->findMatrix(tokens[0], true);
    if (matrix == nullptr) {
        return;
    }
    rank = matrix->getRank();

    std::cout << "Rank of Matrix with id: " << tokens[0] << " = " << rank << std::endl
              << std::endl;
}
