//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_OPERATION_H
#define MATRIXCALC_OPERATION_H

#include <memory>
#include <vector>
#include "../matrix/Matrix.h"


class Operation {
public:
    Operation(std::shared_ptr<Matrix> lhs);

    virtual std::shared_ptr<Matrix> perform() = 0;

protected:
    std::shared_ptr<Matrix> lhs;
    unsigned int newMatrixRows;
    unsigned int newMatrixColumns;
    std::vector<float> newMatrixData;
};


#endif //MATRIXCALC_OPERATION_H
