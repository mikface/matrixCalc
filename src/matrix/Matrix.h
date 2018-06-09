//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_MATRIX_H
#define MATRIXCALC_MATRIX_H

class Matrix {
public:
    Matrix(int rows, int cols);

    double operator()(int row, int col) const;

    void print();

protected:
    virtual float getAt(int row, int column) const = 0;

    int rows;
    int cols;
};


#endif //MATRIXCALC_MATRIX_H
