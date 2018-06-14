//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_OPERATION_H
#define MATRIXCALC_OPERATION_H

#include <memory>
#include <vector>
#include "../matrix/Matrix.h"

/**
 * Base class for unary and binary operations
 */
class Operation {
public:
    /**
     * Constructor
     * @param lhs
     */
    Operation(std::shared_ptr<Matrix> lhs);
    virtual ~Operation();
    /**
     * Performs operation
     * @return new matrix pointer
     */
    virtual std::shared_ptr<Matrix> perform() = 0;

protected:
    /**
     * Left hand side matrix pointer
     */
    std::shared_ptr<Matrix> lhs;

    /**
     * New matrix rows number
     */
    unsigned int newMatrixRows;

    /**
     * New matrix columns number
     */
    unsigned int newMatrixColumns;

    /**
     * New matrix data (stored as dense data, dense vs sparse division happens in Matrix::constructMatrix()
     */
    std::vector<float> newMatrixData;
};


#endif //MATRIXCALC_OPERATION_H
