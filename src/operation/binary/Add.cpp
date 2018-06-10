//
// Created by Mikuláš on 10. 6. 2018.
//

#include "Add.h"
#include "../../calc/Calculator.h"

Add::Add(const std::shared_ptr<Matrix> &lhs, const std::shared_ptr<Matrix> &rhs) : BinaryOperation(lhs, rhs) {
    newMatrixRows = lhs->getRows();
    newMatrixColumns = lhs->getColumns();
}

std::shared_ptr<Matrix> Add::perform() {
    for (unsigned int row = 0; row < newMatrixRows; row++) {
        for (unsigned int column = 0; column < newMatrixColumns; ++column) {
            newMatrixData.push_back((*lhs)(row, column) + (*rhs)(row, column));
        }
    }
    auto result = Calculator::constructMatrix(newMatrixRows, newMatrixColumns, newMatrixData);
    return result;
}
