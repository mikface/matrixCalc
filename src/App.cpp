//
// Created by Mikuláš on 15. 5. 2018.
//

#include "App.h"
#include "matrix/IdentityMatrix.h"
#include <iostream>

void App::run() {
    switch (state) {
        case StateEnum::Main:
            renderMainMenu();
            break;
        default:
            break;
    }
}

void App::renderMainMenu() {
    std::cout << "Welcome";
}

App::App() : state(StateEnum::Main) {
    calc = std::make_unique<Calculator>();
//    Calculator *newCalc = new Calculator();
//    newCalc->saveMatrix("A", std::make_shared<IdentityMatrix>(5));
//    auto newMatrix = newCalc->findMatrix("A");
//    newMatrix->print();
    calc->saveMatrix("A", std::make_shared<IdentityMatrix>(8));
    calc->findMatrix("A")->print();
}