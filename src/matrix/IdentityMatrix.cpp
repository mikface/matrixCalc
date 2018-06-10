//
// Created by Mikuláš on 21. 5. 2018.
//

#include "IdentityMatrix.h"

IdentityMatrix::IdentityMatrix(int size) : Matrix(size, size) {}

float IdentityMatrix::getAt(unsigned int row, unsigned int column) const {
    if (row == column) {
        return 1;
    }
    return 0;
}
