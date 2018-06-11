//
// Created by Mikuláš on 21. 5. 2018.
//

#include <iostream>
#include "Calculator.h"
#include "../matrix/DenseMatrix.h"
#include "../matrix/SparseMatrix.h"
#include "../operation/Gauss.h"

Calculator::Calculator() {

}

std::shared_ptr<Matrix> Calculator::findMatrix(std::string id, bool displayError) {
    auto matrixPointer = storage.find(id);
    if (matrixPointer != storage.end()) {
        return matrixPointer->second;
    }
    if (displayError) {
        std::cout << "No matrix with id '" << id << "' was found in database." << std::endl << std::endl;
    }
    return nullptr;
}

void Calculator::saveMatrix(std::string id, const std::shared_ptr<Matrix> &newMatrix) {

    if (storage.emplace(id, newMatrix).second) {
        std::cout << "Matrix saved, id: " << id << std::endl << std::endl;
    } else {
        std::cout << "Matrix could not be saved, id: " << id << " is already taken." << std::endl
                  << std::endl;
    }
}

void Calculator::deleteMatrix(std::string id, bool displayError) {
    auto matrixPointer = storage.find(id);
    if (matrixPointer != storage.end()) {
        storage.erase(id);
        return;
    }
    if (displayError) {
        std::cout << "No matrix with id '" << id << "' was found in database." << std::endl << std::endl;
    }
}

std::shared_ptr<Matrix>
Calculator::constructMatrix(unsigned int rows, unsigned int columns, std::vector<float> data, bool isGauss) {
    unsigned int nonZeroElemCount = 0, sparseMemory, denseMemory;
    float elem, determinant = 1.0;
    std::shared_ptr<Matrix> newMatrix = nullptr;
    std::map<unsigned int, std::map<unsigned int, float>> sparseData;

    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int column = 0; column < rows; ++column) {
            elem = data[row * columns + column];
            if (elem != 0) {
                sparseData[row].emplace(column, elem);
                nonZeroElemCount++;
            }
        }
    }
    sparseMemory = nonZeroElemCount * 3;
    denseMemory = rows * columns;

    //SPARSE vs DENSE decision point
    if (sparseMemory >= denseMemory) {
        newMatrix = std::make_shared<DenseMatrix>(rows, columns, data);
    } else {
        newMatrix = std::make_shared<SparseMatrix>(rows, columns, sparseData);
    }

    //DETERMINANT FOR SQUARE MATRIX
    if (rows == columns && !isGauss) {
        auto newMatrixGauss = Gauss(newMatrix).perform();
        for (unsigned int row = 0; row < rows; ++row) {
            determinant *= (*newMatrixGauss)(row, row);
        }
        newMatrix->setDeterminant(determinant);
    }

    //DETERMINANT FOR GAUSS MATRIX
    if (isGauss) {
        for (unsigned int row = 0; row < rows; ++row) {
            determinant *= (*newMatrix)(row, row);
        }
        newMatrix->setDeterminant(determinant);
    }

    return newMatrix;
}

