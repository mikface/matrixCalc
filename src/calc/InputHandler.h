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
    /**
     * Constructor, requiring shared pointer to a calculator storage
     * @param calcPtr
     */
    InputHandler(const std::shared_ptr<Calculator> &calcPtr);

    /**
     * Main input parsing function, parses and runs commands
     * @return app state, defining how app will switch and continue it's run
     */
    StateEnum parseCommand();

    /**
     * Helper static function used to tokenize scanned line of input into vector, optional toLower conversion
     * @param toLower
     * @return vector of words from input
     */
    static std::vector<std::string> tokenizeLine(bool toLower);

private:
    /**
     * Calculator storage pointer
     */
    std::shared_ptr<Calculator> calc;

    /**
     * Parsed command pointer, only one is to be parsed and run at one moment
     */
    std::unique_ptr<Command> cmd;
};


#endif //MATRIXCALC_INPUTHANDLER_H
