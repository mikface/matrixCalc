//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_SPLITCOMMAND_H
#define MATRIXCALC_SPLITCOMMAND_H


#include "Command.h"

class SplitCommand : public Command{
public:
    SplitCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);
    virtual void perform() override;

private:
    virtual void sanitize() override;
    std::shared_ptr<Matrix> lhs;
    std::shared_ptr<Matrix> rhs;
    unsigned int rows;
    unsigned int columns;
    unsigned int fromRow;
    unsigned int fromColumn;
    std::shared_ptr<Matrix> result;

};


#endif //MATRIXCALC_SPLITCOMMAND_H
