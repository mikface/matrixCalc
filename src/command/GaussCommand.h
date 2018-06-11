//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_GAUSSCOMMAND_H
#define MATRIXCALC_GAUSSCOMMAND_H


#include "Command.h"

class GaussCommand : public Command {
public:
    GaussCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

    virtual void perform() override;

private:
    virtual void sanitize() override;

    std::shared_ptr<Matrix> lhs;
    std::shared_ptr<Matrix> result;
};


#endif //MATRIXCALC_GAUSSCOMMAND_H
