//
// Created by Mikuláš on 11. 6. 2018.
//

#include "Merge.h"
#include "../../calc/Calculator.h"

Merge::Merge(const std::shared_ptr<Matrix> &lhs, const std::shared_ptr<Matrix> &rhs) : BinaryOperation(lhs, rhs) {
    newMatrixRows = lhs->getRows() > rhs->getRows() ? lhs->getRows() : rhs->getRows();
    newMatrixColumns = lhs->getColumns() + rhs->getColumns();
}

std::shared_ptr<Matrix> Merge::perform() {
    float val;

    for (unsigned int row = 0; row < newMatrixRows; row++) {
        for (unsigned int column = 0; column < newMatrixColumns; ++column) {
            if (column < lhs->getColumns()) {
                //LEFT HAND SIDE MATRIX
                if (row < lhs->getRows()) {
                    val = (*lhs)(row, column);
                } else {
                    //LHS ROW PADDING
                    val = 0;
                }
            } else {
                //RIGHT HAND SIDE MATRIX
                if (row < rhs->getRows()) {
                    val = (*rhs)(row, column - lhs->getColumns());
                } else {
                    //RHS ROW PADDING
                    val = 0;
                }
            }

            newMatrixData.push_back(val);
        }
    }
    auto result = Matrix::constructMatrix(newMatrixRows, newMatrixColumns, newMatrixData);
    return result;
}
