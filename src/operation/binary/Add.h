//
// Created by Mikuláš on 10. 6. 2018.
//

#ifndef MATRIXCALC_ADD_H
#define MATRIXCALC_ADD_H


#include "../BinaryOperation.h"

/**
 * BinaryOperation class used to add two matrices
 */
class Add : public BinaryOperation {
public:
    /**
     * Constructor
     * @param lhs
     * @param rhs
     */
    Add(const std::shared_ptr<Matrix> &lhs, const std::shared_ptr<Matrix> &rhs);

    /**
     * @inherit
     */
    virtual std::shared_ptr<Matrix> perform() override;

};


#endif //MATRIXCALC_ADD_H
