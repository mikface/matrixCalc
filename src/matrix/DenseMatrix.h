//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_DENSEMATRIX_H
#define MATRIXCALC_DENSEMATRIX_H


#include <vector>
#include "Matrix.h"

/**
 * Matrix class for dense matrices, data saved as 1D array with size = rows*columns
 */
class DenseMatrix : public Matrix {
public:
    /**
     * Constructor
     * @param rows
     * @param cols
     * @param dataIn
     */
    DenseMatrix(unsigned int rows, unsigned int cols, const std::vector<float> &dataIn);

private:
    /**
     * @inherit
     */
    virtual float getAt(unsigned int row, unsigned int column) const;

    /**
     * Actual matrix data saved as 1D array
     */
    std::vector<float> data;
};


#endif //MATRIXCALC_DENSEMATRIX_H
