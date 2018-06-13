//
// Created by Mikuláš on 21. 5. 2018.
//
#include <exception>
#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "../operation/Gauss.h"
#include "DenseMatrix.h"
#include "SparseMatrix.h"

Matrix::Matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols), gaussNegativeDeterminant(false) {}

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

float Matrix::getDeterminant() const {
    if (rows == cols) {
        return determinant;
    }

    throw std::invalid_argument("DETERMINANT NOT SUPPORTED FOR RECT MATRIX");
}

unsigned int Matrix::getRank() const {
    return rank;
}

std::shared_ptr<Matrix>
Matrix::constructMatrix(unsigned int rows, unsigned int columns, const std::vector<float> &data) {
    unsigned int nonZeroElemCount = 0, sparseMemory, denseMemory;
    float elem, determinant = 1.0;
    std::shared_ptr<Matrix> newMatrix = nullptr;
    std::map<unsigned int, std::map<unsigned int, float>> sparseData;

    //COUNTING NON ZERO ELEMENTS FOR SPARSE x DENSE decision
    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int column = 0; column < rows; ++column) {
            elem = data[row * columns + column];
            if (elem != 0) {
                sparseData[row].emplace(column, elem);
                nonZeroElemCount++;
            }
        }
    }
    //COUNTING MEMORY TAKEN BY BOTH TYPES
    sparseMemory = nonZeroElemCount * 3;
    denseMemory = rows * columns;

    //SPARSE vs DENSE decision point
    if (sparseMemory >= denseMemory) {
        newMatrix = std::make_shared<DenseMatrix>(rows, columns, data);
    } else {
        newMatrix = std::make_shared<SparseMatrix>(rows, columns, sparseData);
    }

    //MAKING GAUSS MATRIX FOR DETERMINANT AND RANK
    auto newMatrixGauss = Gauss(newMatrix).perform();



    //DETERMINANT FOR SQUARE MATRIX
    if (rows == columns) {
        for (unsigned int row = 0; row < rows; ++row) {
            determinant *= (*newMatrixGauss)(row, row);
        }
        newMatrix->determinant = newMatrixGauss->getDeterminant();
    }

    newMatrix->rank = newMatrixGauss->getRank();


    return newMatrix;
}

std::shared_ptr<Matrix>
Matrix::constructGaussMatrix(unsigned int rows, unsigned int columns, const std::vector<float> &data,
                             bool negativeDeterminant) {
    unsigned int nonZeroElemCount = 0, sparseMemory, denseMemory, rank = 0;
    float elem, determinant = 1.0;
    std::shared_ptr<Matrix> newMatrix = nullptr;
    std::map<unsigned int, std::map<unsigned int, float>> sparseData;

    //COUNTING NON ZERO ELEMENTS FOR SPARSE x DENSE decision
    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int column = 0; column < rows; ++column) {
            elem = data[row * columns + column];
            if (elem != 0) {
                sparseData[row].emplace(column, elem);
                nonZeroElemCount++;
            }
        }
    }
    //COUNTING MEMORY TAKEN BY BOTH TYPES
    sparseMemory = nonZeroElemCount * 3;
    denseMemory = rows * columns;

    //SPARSE vs DENSE decision point
    if (sparseMemory >= denseMemory) {
        newMatrix = std::make_shared<DenseMatrix>(rows, columns, data);
    } else {
        newMatrix = std::make_shared<SparseMatrix>(rows, columns, sparseData);
    }

    //RANK
    for (unsigned int row = 0; row < rows; ++row) {
        bool isZeroRow = true;
        for (unsigned int column = 0; column < columns; column++) {
            if ((*newMatrix)(row, column) != 0) {
                isZeroRow = false;
                break;
            }
        }
        if (!isZeroRow)
            rank++;
    }

    //DETERMINANT FOR GAUSS SQUARE MATRIX
    if (rows == columns) {
        for (unsigned int row = 0; row < rows; ++row) {
            determinant *= (*newMatrix)(row, row);
        }
        if (negativeDeterminant) {
            determinant *= -1;
        }
        newMatrix->determinant = determinant;
    }

    newMatrix->rank = rank;


    return newMatrix;
}

