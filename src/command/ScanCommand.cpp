//
// Created by Mikuláš on 29. 5. 2018.
//

#include <iostream>
#include <typeinfo>
#include <regex>
#include "ScanCommand.h"
#include "../calc/InputHandler.h"


ScanCommand::ScanCommand(const std::vector <std::string> &tokens, const std::shared_ptr <Calculator> &calc) : Command(
        tokens, calc), verbose(false) {
    sanitize();
}

void ScanCommand::sanitize() {
    if (tokens.size() > 4 || tokens.size() < 3) {
        return;
    }

    if (tokens.size() == 4 && tokens[3] == "-v") {
        verbose = true;
    } else if (tokens.size() == 4) {
        return;
    }

    newMatrixName = tokens[0];
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

    if (calc->findMatrix(newMatrixName, false) != nullptr) {
        std::cout << "Matrix can not be scanned, id: " << newMatrixName << " is already taken." << std::endl
                  << std::endl;
        showSyntaxError = false;
        return;
    }
    valid = true;
}

void ScanCommand::perform() {
    loadData();
    newMatrix = Matrix::constructMatrix(rows, columns, data);
    calc->saveMatrix(newMatrixName, newMatrix);
}

void ScanCommand::loadData() {
    unsigned int column;
    float floatElem;
    for (unsigned int row = 0; row < rows; ++row) {
        if (verbose) {
            std::cout << "Please type in matrix column n." << (row + 1) << " and press Enter" << std::endl;
        }
        auto line = InputHandler::tokenizeLine(false);

        //TOO FEW COLUMNS
        while (line.size() < columns) {
            std::cout << "Row n." << (row + 1) << " error: Too few columns" << std::endl;
            if (verbose) {
                std::cout << "Please type in matrix column n." << (row + 1) << " and press Enter" << std::endl;
            }
            line = InputHandler::tokenizeLine(false);
        }

        column = 0;
        for (auto elem: line) {
            //TOO MANY COLUMNS, CUTTING INPUT
            if (column == columns) {
                std::cout << "Too many columns, cutting before element '" << elem << "'" << std::endl
                          << std::endl;
                break;
            }


            try {
                floatElem = std::stof(elem);
            } catch (std::exception e) {
                std::cout << "Invalid argument passed as Matrix element, only floats accepted" << std::endl
                          << std::endl;
                return;
            }

            data.push_back(floatElem);
            column++;
        }
    }
}
