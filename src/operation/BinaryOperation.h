//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_BINARYOPERATION_H
#define MATRIXCALC_BINARYOPERATION_H

#include <memory>
#include "Operation.h"

class BinaryOperation : public Operation {
public:
    BinaryOperation(std::shared_ptr<Matrix> lhs, std::shared_ptr<Matrix> rhs);

private:
    std::shared_ptr<Matrix> rhs;
};


#endif //MATRIXCALC_BINARYOPERATION_H
