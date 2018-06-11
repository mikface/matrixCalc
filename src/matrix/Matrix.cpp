//
// Created by Mikuláš on 21. 5. 2018.
//
#include <exception>
#include <iostream>
#include <cmath>
#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {}

float Matrix::operator()(unsigned int row, unsigned int col) const {
    if (row >= rows || col >= cols)
        throw std::range_error("Matrix out of bounds");
    return getAt(row, col);
}

void Matrix::print() {
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            float val = getAt(i, j);
            if (val == 0) {
                val = std::abs(val);
            }
            std::cout << val << "\t";
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

void Matrix::setDeterminant(float det) {
    determinant = det;
}

float Matrix::getDeterminant() const {
    if (rows == cols) {
        return determinant;
    }

    throw std::invalid_argument("DETERMINANT NOT SUPPORTED FOR RECT MATRIX");
}

