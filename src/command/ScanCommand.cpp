//
// Created by Mikuláš on 29. 5. 2018.
//

#include <iostream>
#include <typeinfo>
#include <regex>
#include "ScanCommand.h"
#include "../calc/InputHandler.h"
#include "../matrix/DenseMatrix.h"


ScanCommand::ScanCommand(const std::vector<std::string> &tokens, const std::shared_ptr<Calculator> &calc) : Command(
        tokens, calc), verbose(false), nonZeroElemCount(0) {
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
    rows = std::stoi(tokens[1]);
    columns = std::stoi(tokens[2]);
    if (rows < 1 || columns < 1) {
        std::cout << "Number of rows / columns must be positive integer" << std::endl << std::endl;
        return;
    }
    valid = true;
}

void ScanCommand::perform() {
    loadData();
    int sparseMemory = nonZeroElemCount * 3;
    int denseMemory = rows * columns;


    if (sparseMemory >= denseMemory) {
        newMatrix = std::make_shared<DenseMatrix>(rows, columns, denseData);
    } else {
        newMatrix = std::make_shared<SparseMatrix>(rows, columns, sparseData);
    }

    if (calc->saveMatrix(newMatrixName, newMatrix)) {
        std::cout << "Matrix saved, id: " << newMatrixName << std::endl << std::endl;
    } else {
        std::cout << "Matrix could not be saved, id: " << newMatrixName << " is already taken." << std::endl
                  << std::endl;
    }

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

            denseData.push_back(floatElem);
            if (floatElem != 0) {
                sparseData[row].emplace(column, floatElem);

                nonZeroElemCount++;
            }
            column++;
        }
    }
}
