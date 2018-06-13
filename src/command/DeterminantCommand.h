//
// Created by Mikuláš on 11. 6. 2018.
//

#ifndef MATRIXCALC_DETERMINANTCOMMAND_H
#define MATRIXCALC_DETERMINANTCOMMAND_H


#include "Command.h"

/**
 * Command class used to get determinant of Matrix
 */
class DeterminantCommand : public Command {
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calculator
     */
    DeterminantCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

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
     * Matrix pointer
     */
    std::shared_ptr<Matrix> matrix;

    /**
     * Result determinant
     */
    float det;
};


#endif //MATRIXCALC_DETERMINANTCOMMAND_H
