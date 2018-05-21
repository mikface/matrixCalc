//
// Created by Mikuláš on 15. 5. 2018.
//

#include "App.h"
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
}