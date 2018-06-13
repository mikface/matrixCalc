//
// Created by Mikuláš on 10. 6. 2018.
//

#include "Multiply.h"
#include "../../matrix/IdentityMatrix.h"
#include "../../calc/Calculator.h"

Multiply::Multiply(const std::shared_ptr<Matrix> &lhs, const std::shared_ptr<Matrix> &rhs) : BinaryOperation(lhs,
                                                                                                             rhs) {
    newMatrixRows = lhs->getRows();
    newMatrixColumns = rhs->getColumns();
}

std::shared_ptr<Matrix> Multiply::perform() {
    for (unsigned int row = 0; row < newMatrixRows; row++) {
        for (unsigned int column = 0; column < newMatrixColumns; ++column) {
            float val = 0;

            for (unsigned int i = 0; i < lhs->getColumns(); i++) {
                val += (*lhs)(row, i) * (*rhs)(i, column);
            }

            newMatrixData.push_back(val);
        }
    }
    auto result = Matrix::constructMatrix(newMatrixRows, newMatrixColumns, newMatrixData);
    return result;
}
