//
// Created by Mikuláš on 21. 5. 2018.
//

#include "BinaryOperation.h"


BinaryOperation::BinaryOperation(std::shared_ptr<Matrix> lhs, std::shared_ptr<Matrix> rhs) : Operation(lhs), rhs(rhs) {}