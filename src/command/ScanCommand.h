//
// Created by Mikuláš on 29. 5. 2018.
//

#ifndef MATRIXCALC_SCANCOMMAND_H
#define MATRIXCALC_SCANCOMMAND_H

#include <vector>
#include <string>
#include "Command.h"
#include "../matrix/SparseMatrix.h"

class ScanCommand : public Command {
public:
    ScanCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calc);

    virtual void perform() override;

private:
    virtual void sanitize() override;

    void loadData();

    unsigned int rows;
    unsigned int columns;
    bool verbose;
    std::vector<float> data;
    std::string newMatrixName;
    std::shared_ptr<Matrix> newMatrix;
};


#endif //MATRIXCALC_SCANCOMMAND_H
