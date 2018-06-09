//
// Created by Mikuláš on 21. 5. 2018.
//

#include "DenseMatrix.h"

float DenseMatrix::getAt(int row, int column) const {
    unsigned int position = (unsigned int) row * rows + column;
    return data.at(position);
}

DenseMatrix::DenseMatrix(int rows, int cols, const std::vector<float> &dataIn) : Matrix(rows, cols), data(dataIn) {

}
