#include <memory>
#include "config/StateEnum.h"
#include "calc/Calculator.h"
#include "calc/InputHandler.h"
#include "calc/Help.h"
//
// Created by Mikuláš on 15. 5. 2018.
//

#ifndef MATRIXCALC_APP_H
#define MATRIXCALC_APP_H


class App {
public:
    /**
     * Main app constructor, sets app state to Main, inits InputHandler and Calculator storage
     */
    App();

    /**
     * Main run function, checks state and controls whole app
     */
    void run();

private:
    /**
     * Input handler
     */
    std::unique_ptr<InputHandler> input;

    /**
     * Calculator storage
     */
    std::shared_ptr<Calculator> calc;

    /**
     * Current state of app
     */
    StateEnum state;
};


#endif //MATRIXCALC_APP_H
