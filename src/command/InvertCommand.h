//
// Created by Mikuláš on 13. 6. 2018.
//

#ifndef MATRIXCALC_INVERTCOMMAND_H
#define MATRIXCALC_INVERTCOMMAND_H


#include "Command.h"
/**
 * Command class used to invert matrix
 */
class InvertCommand : public Command{
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calculator
     */
    InvertCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

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
     * Defines if inverted matrix is saved as new or replaces old one
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


#endif //MATRIXCALC_INVERTCOMMAND_H
