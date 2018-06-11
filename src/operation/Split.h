//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_SPLIT_H
#define MATRIXCALC_SPLIT_H


#include "Operation.h"

class Split : public Operation {
public:
    Split(const std::shared_ptr<Matrix> &lhs, unsigned int fromRow, unsigned int fromColumn, unsigned int rows,
          unsigned int columns);

    virtual std::shared_ptr<Matrix> perform() override;

private:
    unsigned int fromRow;
    unsigned int fromColumn;
};


#endif //MATRIXCALC_SPLIT_H
