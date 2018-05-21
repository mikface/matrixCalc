//
// Created by Mikuláš on 21. 5. 2018.
//

#include "Calculator.h"

Calculator::Calculator() {

}

std::shared_ptr<Matrix> Calculator::findMatrix(std::string id) {
    auto matrixPointer = storage.find(id);
    if (matrixPointer != storage.end()) {
        return matrixPointer->second;
    }
    return nullptr;
}

bool Calculator::saveMatrix(std::string id, const std::shared_ptr<Matrix>& newMatrix) {
    storage.emplace(id, newMatrix);
    return true;
}
