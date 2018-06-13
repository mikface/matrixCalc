//
// Created by Mikuláš on 13. 6. 2018.
//

#ifndef MATRIXCALC_RANKCOMMAND_H
#define MATRIXCALC_RANKCOMMAND_H


#include "../matrix/Matrix.h"
#include "Command.h"

class RankCommand : public Command{
public:
    /**
     * Constructor
     * @param commandTokens
     * @param calculator
     */
    RankCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator);

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
     * Result rank
     */
    float rank;
};


#endif //MATRIXCALC_RANKCOMMAND_H
