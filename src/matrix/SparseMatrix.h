//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_SPARSEMATRIX_H
#define MATRIXCALC_SPARSEMATRIX_H


#include <vector>
#include "Matrix.h"

class SparseMatrix : public Matrix {
public:
    SparseMatrix(int rows, int cols, const std::vector<float> &data, const std::vector<int> &colIndex,
                 const std::vector<int> &rowIndex);

private:
    virtual float getAt(int row, int column) const;

    std::vector<float> data;
    std::vector<int> colIndex;
    std::vector<int> rowIndex;
};


#endif //MATRIXCALC_SPARSEMATRIX_H
