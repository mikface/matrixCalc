//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_IDENTITYMATRIX_H
#define MATRIXCALC_IDENTITYMATRIX_H


#include "Matrix.h"

/**
 * Matrix class for Identity special matrix
 */
class IdentityMatrix : public Matrix {
public:
    /**
     * Constructor
     * @param size
     */
    IdentityMatrix(int size);

private:
    /**
     * @inherit
     */
    virtual float getAt(unsigned int row, unsigned int column) const;
};


#endif //MATRIXCALC_IDENTITYMATRIX_H
