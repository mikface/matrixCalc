//
// Created by Mikuláš on 21. 5. 2018.
//
#include <exception>
#include <iostream>
#include "Matrix.h"

Matrix::Matrix(unsigned int rows,unsigned int cols) : rows(rows), cols(cols) {}

float Matrix::operator()(unsigned int row, unsigned int col) const {
    if (row >= rows || col >= cols)
        throw std::range_error("Matrix out of bounds");
    return getAt(row, col);
}

void Matrix::print() {
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            std::cout << getAt(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

unsigned int Matrix::getRows() const {
    return rows;
}

unsigned int Matrix::getColumns() const {
    return cols;
}

