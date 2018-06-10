//
// Created by Mikuláš on 10. 6. 2018.
//

#ifndef MATRIXCALC_MULTIPLY_H
#define MATRIXCALC_MULTIPLY_H


#include "../BinaryOperation.h"

class Multiply : public BinaryOperation{
public:
    Multiply(const std::shared_ptr<Matrix> &lhs, const std::shared_ptr<Matrix> &rhs);
    virtual std::shared_ptr<Matrix> perform() override ;

};


#endif //MATRIXCALC_MULTIPLY_H
