//
// Created by Mikuláš on 11. 6. 2018.
//
#include <regex>
#include <iostream>
#include "SplitCommand.h"
#include "../operation/Split.h"

SplitCommand::SplitCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator)
        : Command(commandTokens, calculator), fromRow(0), fromColumn(0) {
    sanitize();
}


void SplitCommand::sanitize() {
    if ((tokens.size() != 5 && tokens.size() != 8) || tokens[3] != "=>") {
        return;
    }
    bool checkRows = std::regex_match(tokens[1], std::regex("^\\d+$$"));
    bool checkColumns = std::regex_match(tokens[2], std::regex("^\\d+$$"));

    if (!checkRows || !checkColumns) {
        return;
    }

    rows = (unsigned int) std::stoi(tokens[1]);
    columns = (unsigned int) std::stoi(tokens[2]);
    if (rows < 1 || columns < 1) {
        std::cout << "Number of rows / columns must be greater or equal to 1" << std::endl << std::endl;
        showSyntaxError = false;
        return;
    }

    if (tokens.size() == 8) {
        bool checkFromRows = std::regex_match(tokens[6], std::regex("^\\d+$$"));
        bool checkFromColumns = std::regex_match(tokens[7], std::regex("^\\d+$$"));
        if (!checkFromColumns || !checkFromRows || tokens[5] != "starting")
            return;

        int ifromRow = std::stoi(tokens[6]);
        int ifromColumn = std::stoi(tokens[7]);
        if (ifromRow < 0 || ifromColumn < 0) {
            std::cout << "Position row / column must be greater or equal to 0" << std::endl << std::endl;
            showSyntaxError = false;
            return;
        }
        fromRow = (unsigned int) ifromRow;
        fromColumn = (unsigned int) ifromColumn;
    }

    valid = true;
}

void SplitCommand::perform() {
    lhs = calc->findMatrix(tokens[0], true);

    if (lhs == nullptr) {
        return;
    }

    result = Split(lhs, fromRow, fromColumn, rows, columns).perform();

    calc->saveMatrix(tokens[4], result);
}
