//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_SPLITCOMMAND_H
#define MATRIXCALC_SPLITCOMMAND_H


#include "Command.h"

/**
 * Command class used to split matrix and save only part of it
 */
class SplitCommand : public Command {
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calculator
     */
    SplitCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

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
     * New matrix rows number
     */
    unsigned int rows;

    /**
     * New matrix columns number
     */
    unsigned int columns;

    /**
     * Old matrix starting row
     */
    unsigned int fromRow;

    /**
     * Old matrix starting column
     */
    unsigned int fromColumn;

    /**
     * New matrix pointer
     */
    std::shared_ptr<Matrix> result;

};


#endif //MATRIXCALC_SPLITCOMMAND_H
