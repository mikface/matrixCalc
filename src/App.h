#include "StateEnum.h"
//
// Created by Mikuláš on 15. 5. 2018.
//

#ifndef MATRIXCALC_APP_H
#define MATRIXCALC_APP_H


class App {
public:
    App();
    void run();

private:
    void renderMainMenu();

    StateEnum state;
};


#endif //MATRIXCALC_APP_H
