//
// Created by Mikuláš on 21. 5. 2018.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <regex>
#include "InputHandler.h"
#include "../config/CommandEnum.h"

bool InputHandler::scan() {
    std::string line;
    std::getline(std::cin, line);
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);

    return parseCommand(line);
}

bool InputHandler::parseCommand(std::string line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};

    std::string command = tokens[0];

    //SPECIFIC COMMAND PARSERS
    if (command == CommandEnum::SCAN){

    } else if (command == CommandEnum::CALC){

    } else if (command == CommandEnum::SPLIT){

    } else if (command == CommandEnum::MERGE){

    } else if (command == CommandEnum::GEM){

    }
//
//    for (auto i: tokens) {
//        bool contains_non_alpha = !std::regex_match(i, std::regex("^[a-z]+$"));
//        std::cout << contains_non_alpha << std::endl;
//    }
    return false;
}

