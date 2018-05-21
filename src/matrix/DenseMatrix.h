//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_DENSEMATRIX_H
#define MATRIXCALC_DENSEMATRIX_H


#include <vector>
#include "Matrix.h"

class DenseMatrix : public Matrix{
public:
    DenseMatrix(int rows, int cols);
    virtual float getAt(int row, int column) const ;
private:
    std::vector<std::vector<float>> data;
};


#endif //MATRIXCALC_DENSEMATRIX_H
