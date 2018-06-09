//
// Created by Mikuláš on 15. 5. 2018.
//

#include "App.h"
#include <iostream>

void App::run() {
    while (1) {
        switch (state) {
            case StateEnum::Main:
                state = input->parseCommand();
                break;
            case StateEnum::Help:
                Help::print();
                state = StateEnum::Main;
                break;
            case StateEnum::WrongCommand:
                Help::printWrongCommand();
                state = StateEnum::Main;
                break;
            case StateEnum::Exit:
                std::cout << "It's time to say bye, my precious user <3" << std::endl;
                return;
        }
    }
}

App::App() : state(StateEnum::Main) {
    calc = std::make_shared<Calculator>();
    input = std::make_unique<InputHandler>(calc);
    std::cout << "Welcome to MATRIX CALCULATOR!" << std::endl;
}