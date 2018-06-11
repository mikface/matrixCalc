//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_MERGECOMMAND_H
#define MATRIXCALC_MERGECOMMAND_H


#include "Command.h"

class MergeCommand : public Command{
public:
    MergeCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);
    virtual void perform() override;

private:
    virtual void sanitize() override;
    std::shared_ptr<Matrix> lhs;
    std::shared_ptr<Matrix> rhs;
    std::shared_ptr<Matrix> result;

};


#endif //MATRIXCALC_MERGECOMMAND_H
