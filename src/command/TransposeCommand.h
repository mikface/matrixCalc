//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_TRANSPOSECOMMAND_H
#define MATRIXCALC_TRANSPOSECOMMAND_H


#include "Command.h"

class TransposeCommand : public Command {
public:
    TransposeCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

    virtual void perform() override;

private:
    virtual void sanitize() override;

    bool saveAsNew;
    std::shared_ptr<Matrix> lhs;
    std::shared_ptr<Matrix> result;
};


#endif //MATRIXCALC_TRANSPOSECOMMAND_H
