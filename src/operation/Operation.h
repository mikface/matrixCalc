//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_OPERATION_H
#define MATRIXCALC_OPERATION_H

#include <memory>
#include "../matrix/Matrix.h"


class Operation {
public:
    Operation(std::shared_ptr<Matrix> lhs);

private:
    std::shared_ptr<Matrix> lhs;
};


#endif //MATRIXCALC_OPERATION_H
