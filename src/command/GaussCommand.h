//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_GAUSSCOMMAND_H
#define MATRIXCALC_GAUSSCOMMAND_H


#include "Command.h"

/**
 * Command class used to get echelon form of matrix
 */
class GaussCommand : public Command {
public:

    /**
     * Constructor
     * @param commandTokens
     * @param calculator
     */
    GaussCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

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
     * Left hand side matrix pointer
     */
    std::shared_ptr<Matrix> lhs;

    /**
     * Result matrix pointer
     */
    std::shared_ptr<Matrix> result;
};


#endif //MATRIXCALC_GAUSSCOMMAND_H
