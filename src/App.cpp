//
// Created by Mikuláš on 15. 5. 2018.
//

#include "App.h"
#include <iostream>

void App::run() {
    if (input->scan()) {
        state = StateEnum::Command;
        switchState();
    } else {
        state = StateEnum::Help;
        switchState();
    }
}

void App::switchState() {
    switch (state) {
        case StateEnum::Command:
            break;
        case StateEnum::Help:
            Help::print();
            state = StateEnum::Main;
            run();
            break;
        default:
            throw std::invalid_argument("Switchstate doesn't exist");
    }
}

App::App() : state(StateEnum::Main) {
    calc = std::make_unique<Calculator>();
    input = std::make_unique<InputHandler>();
    std::cout << "Welcome to MATRIX CALCULATOR!" << std::endl;
}