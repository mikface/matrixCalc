//
// Created by Mikuláš on 11. 6. 2018.
//

#include <iostream>
#include <cmath>
#include "Gauss.h"
#include "../calc/Calculator.h"

Gauss::Gauss(const std::shared_ptr<Matrix> &lhs) : Operation(lhs) {
    newMatrixRows = lhs->getRows();
    newMatrixColumns = lhs->getColumns();
}

std::shared_ptr<Matrix> Gauss::perform() {
    unsigned int rows = newMatrixRows, cols = newMatrixColumns, i, j, k;
    float a[rows][cols];
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            a[i][j] = (*lhs)(i, j);    //input the elements of matrix

    for (i = 0; i < rows; i++)                    //Pivotisation
        for (k = i + 1; k < rows; k++)
            if (std::abs(a[i][i]) < std::abs(a[k][i]))
                for (j = 0; j < cols; j++) {
                    float temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
    for (i = 0; i < rows - 1; i++)            //loop to perform the gauss elimination
        for (k = i + 1; k < rows; k++) {
            float t = a[k][i] / a[i][i];
            for (j = 0; j < cols; j++)
                a[k][j] = a[k][j] - t *
                                    a[i][j];    //make the elements below the pivot elements equal to zero or eliminate the variables
        }
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++) {
            newMatrixData.push_back((float) (std::round(a[i][j] * 1000.0) / 1000.0));
        }
    auto result = Calculator::constructMatrix(newMatrixRows, newMatrixColumns, newMatrixData, true);
    return result;
}
