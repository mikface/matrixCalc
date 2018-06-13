//
// Created by Mikuláš on 29. 5. 2018.
//

#ifndef MATRIXCALC_SCANCOMMAND_H
#define MATRIXCALC_SCANCOMMAND_H

#include <vector>
#include <string>
#include "Command.h"
#include "../matrix/SparseMatrix.h"

/**
 * Command class used to scan new matrix
 */
class ScanCommand : public Command {
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calc
     */
    ScanCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calc);

    /**
     * @inherit
     */
    virtual void perform() override;

private:
    /**
     * @inherit
     */
    virtual void sanitize() override;

    /**
     * Loads matrix data from input and validates them / prints custom errors
     */
    void loadData();

    /**
     * New matrix rows number
     */
    unsigned int rows;

    /**
     * New matrix columns number
     */
    unsigned int columns;

    /**
     * Determines if scan command helps user with inputing matrix with comments
     */
    bool verbose;

    /**
     * New matrix data
     */
    std::vector<float> data;

    /**
     * New matrix name (ID)
     */
    std::string newMatrixName;

    /**
     * New matrix pointer
     */
    std::shared_ptr<Matrix> newMatrix;
};


#endif //MATRIXCALC_SCANCOMMAND_H
