//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_IDENTITYMATRIX_H
#define MATRIXCALC_IDENTITYMATRIX_H


#include "Matrix.h"

class IdentityMatrix : public Matrix {
public:
    IdentityMatrix(int size);

private:
    virtual float getAt(unsigned int row, unsigned int column) const;
};


#endif //MATRIXCALC_IDENTITYMATRIX_H
