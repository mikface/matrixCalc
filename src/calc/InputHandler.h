//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_INPUTHANDLER_H
#define MATRIXCALC_INPUTHANDLER_H


#include <queue>
#include "../command/Command.h"
#include "Calculator.h"
#include "../config/StateEnum.h"

class InputHandler {
public:
    InputHandler(const std::shared_ptr<Calculator> &calcPtr);

    StateEnum parseCommand();

    static std::vector<std::string> tokenizeLine(bool toLower);

private:

    std::shared_ptr<Calculator> calc;
    std::unique_ptr<Command> cmd;
};


#endif //MATRIXCALC_INPUTHANDLER_H
