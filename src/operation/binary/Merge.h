//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_MERGE_H
#define MATRIXCALC_MERGE_H


#include "../BinaryOperation.h"

class Merge : public BinaryOperation{
public:
    Merge(const std::shared_ptr<Matrix> &lhs, const std::shared_ptr<Matrix> &rhs);

    virtual std::shared_ptr<Matrix> perform() override ;

};


#endif //MATRIXCALC_MERGE_H
