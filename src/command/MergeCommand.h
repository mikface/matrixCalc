//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_MERGECOMMAND_H
#define MATRIXCALC_MERGECOMMAND_H


#include "Command.h"

/**
 * Command class used to merge two matrices
 */
class MergeCommand : public Command {
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calculator
     */
    MergeCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

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
     * Right hand side matrix pointer
     */
    std::shared_ptr<Matrix> rhs;

    /**
     * Result (new) matrix pointer
     */
    std::shared_ptr<Matrix> result;
};


#endif //MATRIXCALC_MERGECOMMAND_H
