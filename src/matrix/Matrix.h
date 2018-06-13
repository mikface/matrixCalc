//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_MATRIX_H
#define MATRIXCALC_MATRIX_H

#include <memory>
#include <vector>

/**
 * Base class for all types of Matrix
 */
class Matrix {
public:
    /**
     * Matrix constructor
     * @param rows
     * @param cols
     */
    Matrix(unsigned int rows, unsigned int cols);

    /**
     * Public function to access matrix element
     * @param row
     * @param col
     * @return matrix element
     */
    float operator()(unsigned int row, unsigned int col) const;

    /**
     * Print the matrix
     */
    void print();

    /**
     * Row count getter
     * @return number of rows
     */
    unsigned int getRows() const;

    /**
     * Column count getter
     * @return number of columns
     */
    unsigned int getColumns() const;

    /**
     * Get matrix determinant
     * @return determinant
     */
    float getDeterminant() const;

    /**
     * Static function for constructing new matrix
     * @return shared pointer to new matrix
     */
    static std::shared_ptr<Matrix>
    constructMatrix(unsigned int rows, unsigned int columns, std::vector<float> data, bool isGauss = false,
                    bool negativeDeterminant = false);

protected:
    /**
     * Actual function for accessing matrix element, implemented by type of matrix
     * @param row
     * @param column
     * @return matrix element
     */
    virtual float getAt(unsigned int row, unsigned int column) const = 0;

    /**
     * Matrix height (number of rows)
     */
    unsigned int rows;

    /**
     * Matrix width (number of columns)
     */
    unsigned int cols;

    /**
     * Matrix determinant
     */
    float determinant;

    /**
     * Determines if during Gauss rows were switched (negative determinant issue)
     */
    bool gaussNegativeDeterminant;
};


#endif //MATRIXCALC_MATRIX_H
