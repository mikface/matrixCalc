//
// Created by Mikuláš on 11. 6. 2018.
//

#include "Split.h"
#include "../calc/Calculator.h"

Split::Split(const std::shared_ptr<Matrix> &lhs, unsigned int fromRow, unsigned int fromColumn, unsigned int rows,
             unsigned int columns) : Operation(lhs) {
    newMatrixRows = rows;
    newMatrixColumns = columns;
    this->fromRow = fromRow;
    this->fromColumn = fromColumn;
}

std::shared_ptr<Matrix> Split::perform() {
    float val;

    for (unsigned int row = 0; row < newMatrixRows; row++) {
        for (unsigned int column = 0; column < newMatrixColumns; ++column) {

            if ((column + fromColumn) < lhs->getColumns() && (row + fromRow) < lhs->getRows()) {
                //ELEMENT IN MATRIX
                val = (*lhs)((row + fromRow), (column + fromColumn));
            } else {
                //PADDING
                val = 0;
            }


            newMatrixData.push_back(val);
        }
    }
    auto result = Matrix::constructMatrix(newMatrixRows, newMatrixColumns, newMatrixData);
    return result;
}
