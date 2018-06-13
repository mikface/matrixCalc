//
// Created by Mikuláš on 15. 5. 2018.
//

#ifndef MATRIXCALC_HELP_H
#define MATRIXCALC_HELP_H

/**
 * Static - like used class for printing help and syntax error
 */
class Help {
public:
    /**
     * Prints help with supported commands and syntax.
     */
    static void print();

    /**
     * Prints error for wrong command syntax
     */
    static void printWrongCommand();
};


#endif //MATRIXCALC_HELP_H
