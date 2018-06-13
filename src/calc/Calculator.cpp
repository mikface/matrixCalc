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
