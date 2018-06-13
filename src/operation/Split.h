//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_SPLIT_H
#define MATRIXCALC_SPLIT_H


#include "Operation.h"

/**
 * Operation class used to split matrix
 */
class Split : public Operation {
public:
    /**
     * Constructor setting position and size fo split matrix
     * @param lhs
     * @param fromRow
     * @param fromColumn
     * @param rows
     * @param columns
     */
    Split(const std::shared_ptr<Matrix> &lhs, unsigned int fromRow, unsigned int fromColumn, unsigned int rows,
          unsigned int columns);

    /**
     * Matrix is split and if size is bigger than original one, rest is padded with zeros
     * @return new matrix pointer
     */
    virtual std::shared_ptr<Matrix> perform() override;

private:
    /**
     * Row position of split (default is 0)
     */
    unsigned int fromRow;

    /**
     * Column position of split (defailt is 0)
     */
    unsigned int fromColumn;
};


#endif //MATRIXCALC_SPLIT_H
