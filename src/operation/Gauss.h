//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_GAUSS_H
#define MATRIXCALC_GAUSS_H


#include "Operation.h"

/**
 * Operation class used to transform matrix into echelon form
 */
class Gauss : public Operation {
public:
    /**
     * Constructor
     * @param lhs
     */
    Gauss(const std::shared_ptr<Matrix> &lhs);

    /**
     * @inherit
     */
    virtual std::shared_ptr<Matrix> perform() override;

};


#endif //MATRIXCALC_GAUSS_H
