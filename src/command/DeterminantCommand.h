//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_DETERMINANTCOMMAND_H
#define MATRIXCALC_DETERMINANTCOMMAND_H


#include "Command.h"

class DeterminantCommand : public Command {
public:
    DeterminantCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

    virtual void perform() override;

private:
    virtual void sanitize() override;

    std::shared_ptr<Matrix> matrix;
    float det;
};


#endif //MATRIXCALC_DETERMINANTCOMMAND_H
