//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_MATRIX_H
#define MATRIXCALC_MATRIX_H

class Matrix {
public:
    Matrix(unsigned int rows, unsigned int cols);

    float operator()(unsigned int row, unsigned int col) const;

    void print();

    unsigned int getRows() const;

    unsigned int getColumns() const;

protected:
    virtual float getAt(unsigned int row, unsigned int column) const = 0;

    unsigned int rows;
    unsigned int cols;
};


#endif //MATRIXCALC_MATRIX_H
