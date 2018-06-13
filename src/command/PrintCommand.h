//
// Created by Mikuláš on 9. 6. 2018.
//

#ifndef MATRIXCALC_PRINTCOMMAND_H
#define MATRIXCALC_PRINTCOMMAND_H


#include <vector>
#include <memory>
#include "Command.h"

/**
 * Command class used to print matrix
 */
class PrintCommand : public Command {
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calc
     */
    PrintCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calc);

    /**
     * @inherit
     */
    virtual void perform() override;

private:
    /**
     * @inherit
     */
    virtual void sanitize() override;

    /**
     * ID of matrix to be printed
     */
    std::string matrixID;
};


#endif //MATRIXCALC_PRINTCOMMAND_H
