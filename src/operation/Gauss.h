//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_GAUSS_H
#define MATRIXCALC_GAUSS_H


#include "Operation.h"

class Gauss : public Operation {
public:
    Gauss(const std::shared_ptr<Matrix> &lhs);

    virtual std::shared_ptr<Matrix> perform() override;

};


#endif //MATRIXCALC_GAUSS_H
