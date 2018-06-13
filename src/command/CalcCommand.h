//
// Created by Mikuláš on 10. 6. 2018.
//

#ifndef MATRIXCALC_CALCCOMMAND_H
#define MATRIXCALC_CALCCOMMAND_H


#include "Command.h"

class CalcCommand : public Command {
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calculator
     */
    CalcCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

    /**
     * @inherit
     */
    virtual void perform() override;

private:

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

    /**
     * @inherit
     */
    virtual void sanitize() override;

};


#endif //MATRIXCALC_CALCCOMMAND_H
