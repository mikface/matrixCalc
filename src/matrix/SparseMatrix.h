//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_SPARSEMATRIX_H
#define MATRIXCALC_SPARSEMATRIX_H


#include <map>
#include "Matrix.h"

/**
 * Matrix class for sparse matrices, data saved as map (rows) of maps (columns => value), memory efficient
 */
class SparseMatrix : public Matrix {
public:
    /**
     * Constructor
     * @param rows
     * @param cols
     * @param data
     */
    SparseMatrix(int rows, int cols, const std::map<unsigned int, std::map<unsigned int, float>> &data);

private:
    /**
     * @inherit
     */
    virtual float getAt(unsigned int row, unsigned int column) const;

    /**
     * Matrix data
     */
    std::map<unsigned int, std::map<unsigned int, float>> data;
};


#endif //MATRIXCALC_SPARSEMATRIX_H
