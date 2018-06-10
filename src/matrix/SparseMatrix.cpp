//
// Created by Mikuláš on 21. 5. 2018.
//

#include "SparseMatrix.h"


SparseMatrix::SparseMatrix(int rows, int cols, const std::map<unsigned int, std::map<unsigned int, float>> &dataIn)
        : Matrix(rows, cols),
          data(dataIn) {
}

float SparseMatrix::getAt(unsigned int row, unsigned int column) const {
    float element;
    try {
        element = data.at(row).at(column);
    } catch (std::exception e) {
        return 0;
    }

    return element;
}
