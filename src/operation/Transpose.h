//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_TRANSPOSE_H
#define MATRIXCALC_TRANSPOSE_H


#include "Operation.h"

/**
 * Operation class used to transpose matrix
 */
class Transpose : public Operation {
public:
    /**
     * Constructor
     * @param lhs
     */
    Transpose(const std::shared_ptr<Matrix> &lhs);

    /**
     * @inherit
     */
    virtual std::shared_ptr<Matrix> perform() override;
};


#endif //MATRIXCALC_TRANSPOSE_H
