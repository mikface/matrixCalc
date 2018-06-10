//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_SPARSEMATRIX_H
#define MATRIXCALC_SPARSEMATRIX_H


#include <map>
#include "Matrix.h"

class SparseMatrix : public Matrix {
public:
    SparseMatrix(int rows, int cols, const std::map<unsigned int,std::map<unsigned int, float>> &data);

private:
    virtual float getAt(unsigned int row, unsigned int column) const;

    std::map<unsigned int,std::map<unsigned int, float>> data;
};


#endif //MATRIXCALC_SPARSEMATRIX_H
