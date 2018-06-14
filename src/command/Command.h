//
// Created by Mikuláš on 22. 5. 2018.
//

#ifndef MATRIXCALC_COMMAND_H
#define MATRIXCALC_COMMAND_H


#include <memory>
#include <vector>
#include <string>
#include "../calc/Calculator.h"

/**
 * Base class for all types of commands being supported by Application
 */
class Command {
public:
    /**
     * Base command class contructor
     * @param commandTokens
     * @param calculator
     */
    Command(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);
    virtual ~Command();
    /**
     * Performs the command, requires valid command syntax (checked in sanitize() function)
     */
    virtual void perform() = 0;

    /**
     * Returns info if command is valid
     * @return command is/is not valid
     */
    bool isValid() const;

    /**
     * Returns info about outputing syntax error
     * @return
     */
    bool syntaxError() const;

protected:
    /**
     * Validates input and outputs error if input is not valid
     */
    virtual void sanitize() = 0;

    /**
     * Command is / is not valid
     */
    bool valid;

    /**
     * Show custom / syntax error
     */
    bool showSyntaxError;

    /**
     * Calculator storage pointer
     */
    std::shared_ptr<Calculator> calc;

    /**
     * Tokenized command words
     */
    std::vector<std::string> tokens;
};


#endif //MATRIXCALC_COMMAND_H
