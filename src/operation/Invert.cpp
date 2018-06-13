//
// Created by Mikuláš on 13. 6. 2018.
//

#include <iostream>
#include <cmath>
#include "Invert.h"

Invert::Invert(const std::shared_ptr<Matrix> &lhs) : Operation(lhs) {
    newMatrixRows = lhs->getRows();
    newMatrixColumns = lhs->getColumns();
}

std::shared_ptr<Matrix> Invert::perform() {
    unsigned int k;
    std::vector<std::vector<float>> a(newMatrixRows, std::vector<float>(2 * newMatrixRows));
    float floatEl;


    //input the elements of help matrix
    for (unsigned int i = 0; i < newMatrixRows; i++) {
        for (unsigned int j = 0; j < newMatrixRows; j++) {
            a[i][j] = (*lhs)(i, j);
        }
    }

    //IndetityMatrix Merge
    for (unsigned int i = 0; i < newMatrixRows; i++) {
        for (unsigned int j = newMatrixRows; j < 2 * newMatrixRows; j++) {
            if (i == j - newMatrixRows)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    //Elimination
    for (unsigned int i = 0; i < newMatrixRows; i++) {
        floatEl = a[i][i];
        for (unsigned int j = i; j < 2 * newMatrixRows; j++)
            a[i][j] = a[i][j] / floatEl;
        for (unsigned int j = 0; j < newMatrixRows; j++) {
            if (i != j) {
                floatEl = a[j][i];
                for (k = 0; k < 2 * newMatrixRows; k++)
                    a[j][k] = a[j][k] - floatEl * a[i][k];
            }
        }
    }

    //Saving data
    for (unsigned int i = 0; i < newMatrixRows; i++) {
        for (unsigned int j = newMatrixRows; j < 2 * newMatrixRows; j++) {
            newMatrixData.push_back((float) (std::round(a[i][j] * 1000.0) / 1000.0));
        }
    }

    auto result = Matrix::constructMatrix(newMatrixRows, newMatrixColumns, newMatrixData);
    return result;
}
