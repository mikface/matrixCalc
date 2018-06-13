//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_MERGE_H
#define MATRIXCALC_MERGE_H


#include "../BinaryOperation.h"

/**
 * BinaryOperation class used to merge two matrices
 */
class Merge : public BinaryOperation {
public:
    /**
     * Constructor
     * @param lhs
     * @param rhs
     */
    Merge(const std::shared_ptr<Matrix> &lhs, const std::shared_ptr<Matrix> &rhs);

    /**
     * @inherit
     */
    virtual std::shared_ptr<Matrix> perform() override;

};


#endif //MATRIXCALC_MERGE_H
