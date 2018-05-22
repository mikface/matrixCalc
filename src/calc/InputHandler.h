//
// Created by Mikuláš on 21. 5. 2018.
//

#ifndef MATRIXCALC_INPUTHANDLER_H
#define MATRIXCALC_INPUTHANDLER_H


class InputHandler {
public:
    bool scan();
private:
    bool parseCommand(std::string line);
};


#endif //MATRIXCALC_INPUTHANDLER_H
