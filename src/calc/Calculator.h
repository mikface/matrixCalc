//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_CALCULATOR_H
#define MATRIXCALC_CALCULATOR_H


#include <map>
#include <string>
#include <memory>
#include <vector>
#include "../matrix/Matrix.h"

class Calculator {
public:
    Calculator();

    void saveMatrix(std::string id, const std::shared_ptr<Matrix> &newMatrix);

    std::shared_ptr<Matrix> findMatrix(std::string id, bool displayError);

    void deleteMatrix(std::string id, bool displayError);

    static std::shared_ptr<Matrix>
    constructMatrix(unsigned int rows, unsigned int columns, std::vector<float> data, bool isGauss);

private:
    std::map<std::string, std::shared_ptr<Matrix>> storage;
};


#endif //MATRIXCALC_CALCULATOR_H
