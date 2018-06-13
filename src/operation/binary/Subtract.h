//
// Created by Mikuláš on 10. 6. 2018.
//

#ifndef MATRIXCALC_SUBTRACT_H
#define MATRIXCALC_SUBTRACT_H


#include "../BinaryOperation.h"

/**
 * BinaryOperation class used to subtract two matrices
 */
class Subtract : public BinaryOperation {
public:
    /**
     * Constructor
     * @param lhs
     * @param rhs
     */
    Subtract(const std::shared_ptr<Matrix> &lhs, const std::shared_ptr<Matrix> &rhs);

    /**
     * @inherit
     */
    virtual std::shared_ptr<Matrix> perform() override;

};


#endif //MATRIXCALC_SUBTRACT_H
