//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_BINARYOPERATION_H
#define MATRIXCALC_BINARYOPERATION_H

#include <memory>
#include "Operation.h"

/**
 * Base class for binary operations, derived from Operation
 */
class BinaryOperation : public Operation {
public:
    /**
     * Constructor (mention right hand side matrix)
     * @param lhs
     * @param rhs
     */
    BinaryOperation(std::shared_ptr<Matrix> lhs, std::shared_ptr<Matrix> rhs);

protected:
    /**
     * Right hand side matrix pointer
     */
    std::shared_ptr<Matrix> rhs;
};


#endif //MATRIXCALC_BINARYOPERATION_H
