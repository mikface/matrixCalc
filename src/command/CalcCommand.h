//
// Created by Mikuláš on 10. 6. 2018.
//

#ifndef MATRIXCALC_CALCCOMMAND_H
#define MATRIXCALC_CALCCOMMAND_H


#include "Command.h"

class CalcCommand : public Command {
public:
    CalcCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);


    virtual void perform() override;

private:
    std::shared_ptr<Matrix> lhs;
    std::shared_ptr<Matrix> rhs;
    std::shared_ptr<Matrix> result;
    virtual void sanitize() override;

};


#endif //MATRIXCALC_CALCCOMMAND_H
