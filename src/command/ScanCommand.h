//
// Created by Mikuláš on 29. 5. 2018.
//

#ifndef MATRIXCALC_SCANCOMMAND_H
#define MATRIXCALC_SCANCOMMAND_H

#include <vector>
#include <string>
#include "Command.h"

class ScanCommand : public Command {
public:
    ScanCommand(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calc);

    virtual void perform() override;

private:
    virtual void sanitize() override;

    void loadData();

    int rows;
    int columns;
    bool verbose;
    int nonZeroElemCount;
    std::vector<float> denseData;
    std::vector<float> sparseData;
    std::vector<int> colIndex;
    std::vector<int> rowIndex;
    std::string newMatrixName;
    std::shared_ptr<Matrix> newMatrix;
};


#endif //MATRIXCALC_SCANCOMMAND_H
