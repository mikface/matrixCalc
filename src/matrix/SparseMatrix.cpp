//
// Created by Mikuláš on 21. 5. 2018.
//

#include "SparseMatrix.h"


SparseMatrix::SparseMatrix(int rows, int cols, const std::vector<float> &dataIn, const std::vector<int> &colIndexIn,
                           const std::vector<int> &rowIndexIn) : Matrix(rows, cols), data(dataIn),
                                                                 colIndex(colIndexIn), rowIndex(rowIndexIn) {
}

float SparseMatrix::getAt(int row, int column) const {
    return 0;
}
