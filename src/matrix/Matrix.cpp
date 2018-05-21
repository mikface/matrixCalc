//
// Created by Mikuláš on 21. 5. 2018.
//
#include <exception>
#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {}

double Matrix::operator()(int row, int col) const {
    if (row >= rows || col >= cols)
        throw std::range_error("Matrix out of bounds");
    return getAt(row, col);
}

void Matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << getAt(i, j)<<" ";
        }
        std::cout << std::endl;
    }
}

