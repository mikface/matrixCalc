//
// Created by Mikuláš on 22. 5. 2018.
//
#include <string>

#ifndef MATRIXCALC_COMMANDENUM_H
#define MATRIXCALC_COMMANDENUM_H

/**
 * Supported commands' enum class (not real enum, string used as command id)
 */
class CommandEnum {
public:
    static const std::string SPLIT;
    static const std::string CALC;
    static const std::string MERGE;
    static const std::string GEM;
    static const std::string SCAN;
    static const std::string PRINT;
//    static const std::string DELETE;
    static const std::string TRANSPOSE;
    static const std::string DETERMINANT;
    static const std::string RANK;
    static const std::string EXIT;
};

#endif //MATRIXCALC_COMMANDENUM_H
