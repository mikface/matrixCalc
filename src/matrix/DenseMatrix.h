//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_DENSEMATRIX_H
#define MATRIXCALC_DENSEMATRIX_H


#include <vector>
#include "Matrix.h"

class DenseMatrix : public Matrix {
public:
    DenseMatrix(int rows, int cols, const std::vector<float> &dataIn);

private:
    virtual float getAt(unsigned int row, unsigned int column) const;

    std::vector<float> data;
};


#endif //MATRIXCALC_DENSEMATRIX_H
