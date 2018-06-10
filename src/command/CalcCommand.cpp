//
// Created by Mikuláš on 10. 6. 2018.
//
#include <regex>
#include <iostream>
#include "CalcCommand.h"
#include "../operation/binary/Add.h"
#include "../operation/binary/Subtract.h"
#include "../operation/binary/Multiply.h"

CalcCommand::CalcCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator)
        : Command(commandTokens, calculator) {
    sanitize();
}

void CalcCommand::sanitize() {

    if (tokens.size() != 5 || tokens[1] != "=" || !std::regex_match(tokens[3], std::regex("^(\\+|\\-|\\*)$"))) {
        return;
    }

    if (calc->findMatrix(tokens[0], false) != nullptr) {
        std::cout << "Matrix can not be saved, id: " << tokens[0] << " is already taken." << std::endl
                  << std::endl;
        showSyntaxError = false;
        return;
    }

    valid = true;
}

void CalcCommand::perform() {
    lhs = calc->findMatrix(tokens[2], true);
    rhs = calc->findMatrix(tokens[4], true);

    if (rhs == nullptr || lhs == nullptr) {
        return;
    }
    int lhsRows = lhs->getRows(), lhsColumns = lhs->getColumns(),
            rhsRows = rhs->getRows(), rhsColumns = rhs->getColumns();

    if (tokens[3] == "+") {
        if (lhsRows == rhsRows && lhsColumns == rhsColumns) {
            result = Add(lhs, rhs).perform();
        } else {
            std::cout << "Oops, can not add two matrices of different dimensions." << std::endl << std::endl;
            return;
        }
    } else if (tokens[3] == "-") {
        if (lhsRows == rhsRows && lhsColumns == rhsColumns) {
            result = Subtract(lhs, rhs).perform();
        } else {
            std::cout << "Oops, can not subtract two matrices of different dimensions." << std::endl << std::endl;
            return;
        }
    } else if (tokens[3] == "*") {

        if (lhsColumns == rhsRows) {
            result = Multiply(lhs, rhs).perform();
        } else {
            std::cout << "Oops, can not multiply these two matrices, wrong dimensions." << std::endl << std::endl;
            return;
        }
    }

    calc->saveMatrix(tokens[0], result);
}

