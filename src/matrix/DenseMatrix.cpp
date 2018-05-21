//
// Created by Mikuláš on 21. 5. 2018.
//

#include "DenseMatrix.h"


DenseMatrix::DenseMatrix(int rows, int cols) : Matrix(rows, cols) {}

float DenseMatrix::getAt(int row, int column) const {
    return data[row][column];
}
