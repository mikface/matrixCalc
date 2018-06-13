//
// Created by Mikuláš on 13. 6. 2018.
//

#ifndef MATRIXCALC_INVERT_H
#define MATRIXCALC_INVERT_H


#include "Operation.h"

/**
 * Operation class used to invert matrix
 */
class Invert : public Operation {
public:
    /**
     * Constructor
     * @param lhs
     */
    Invert(const std::shared_ptr<Matrix> &lhs);

    /**
     * @inherit
     */
    virtual std::shared_ptr<Matrix> perform() override;

};


#endif //MATRIXCALC_INVERT_H
