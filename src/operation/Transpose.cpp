//
// Created by Mikuláš on 11. 6. 2018.
//

#include "Transpose.h"
#include "../calc/Calculator.h"

Transpose::Transpose(const std::shared_ptr<Matrix> &lhs) : Operation(lhs) {
    newMatrixRows = lhs->getColumns();
    newMatrixColumns = lhs->getRows();
}

std::shared_ptr<Matrix> Transpose::perform() {
    for (unsigned int column = 0; column < lhs->getColumns(); ++column) {
        for (unsigned int row = 0; row < lhs->getRows(); row++) {
            newMatrixData.push_back((*lhs)(row, column));
        }
    }
    auto result = Matrix::constructMatrix(newMatrixRows, newMatrixColumns, newMatrixData);
    return result;
}
