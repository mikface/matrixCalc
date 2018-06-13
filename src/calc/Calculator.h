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
    /**
     * Calculator storage constructor
     */
    Calculator();

    /**
     * Saves new matrix into calculator storage
     * @param id
     * @param newMatrix
     */
    void saveMatrix(std::string id, const std::shared_ptr<Matrix> &newMatrix);

    /**
     * Looks for matrix in calculator storage
     * @param id
     * @param displayError
     * @return shared pointer of found matrix, if none is found nullptr is returned
     */
    std::shared_ptr<Matrix> findMatrix(std::string id, bool displayError);

    /**
     * Deletes matrix from storage
     * @param id
     * @param displayError
     */
    void deleteMatrix(std::string id, bool displayError);

private:
    /**
     * Matrix calculator storage. Matrices are stored with unique id as key in the map, shared pointer to matrix being the value.
     */
    std::map<std::string, std::shared_ptr<Matrix>> storage;
};


#endif //MATRIXCALC_CALCULATOR_H
