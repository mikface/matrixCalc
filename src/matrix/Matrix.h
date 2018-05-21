//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_MATRIX_H
#define MATRIXCALC_MATRIX_H

#include <memory>

class Matrix {
public:
    Matrix(int rows, int cols);

    virtual float getAt(int row, int column) const = 0;

    double operator()(int row, int col) const;

private:
    int rows;
    int cols;
};


#endif //MATRIXCALC_MATRIX_H
