//
// Created by Mikuláš on 22. 5. 2018.
//

#ifndef MATRIXCALC_COMMAND_H
#define MATRIXCALC_COMMAND_H


#include <memory>
#include <vector>
#include <string>
#include "../calc/Calculator.h"

class Command {
public:
    Command(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

    virtual void perform() = 0;

    bool isValid();

protected:
    virtual void sanitize() = 0;

    bool valid;
    std::shared_ptr<Calculator> calc;
    std::vector<std::string> tokens;
};


#endif //MATRIXCALC_COMMAND_H
