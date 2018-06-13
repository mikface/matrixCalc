//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_TRANSPOSECOMMAND_H
#define MATRIXCALC_TRANSPOSECOMMAND_H


#include "Command.h"

/**
 * Command class used to transpose matrix
 */
class TransposeCommand : public Command {
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calculator
     */
    TransposeCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

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
     * Defines if transposed matrix is saved as new or replaces old one
     */
    bool saveAsNew;

    /**
     * Left hand side matrix pointer
     */
    std::shared_ptr<Matrix> lhs;

    /**
     * New (result) matrix pointer
     */
    std::shared_ptr<Matrix> result;
};


#endif //MATRIXCALC_TRANSPOSECOMMAND_H
