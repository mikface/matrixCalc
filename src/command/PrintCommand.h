//
// Created by Mikuláš on 9. 6. 2018.
//

#ifndef MATRIXCALC_PRINTCOMMAND_H
#define MATRIXCALC_PRINTCOMMAND_H


#include <vector>
#include <memory>
#include "Command.h"

class PrintCommand : public Command {
public:
    PrintCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calc);

    virtual void perform() override;

private:
    virtual void sanitize() override;

    std::string matrixID;
};


#endif //MATRIXCALC_PRINTCOMMAND_H
