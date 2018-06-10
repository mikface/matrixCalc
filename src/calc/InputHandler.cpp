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
#include "../command/ScanCommand.h"
#include "../command/PrintCommand.h"
#include "../command/CalcCommand.h"
#include "../command/TransposeCommand.h"


InputHandler::InputHandler(const std::shared_ptr<Calculator> &calcPtr) {
    calc = std::make_shared<Calculator>((*calcPtr));
}


StateEnum InputHandler::parseCommand() {
    std::vector<std::string> tokens = InputHandler::tokenizeLine(true);

    //EMPTY COMMAND, NOTHING HAPPENS
    if (tokens.empty()) {
        return StateEnum::Main;
    }
    //GET ACTUAL COMMAND
    std::string command = tokens[0];

    //DELETE ACTUAL COMMAND FROM PARSED ARRAY
    tokens.erase(tokens.begin());

    //SPECIFIC COMMAND PARSERS
    if (command == CommandEnum::SCAN) {
        cmd = std::make_unique<ScanCommand>(tokens, calc);
    } else if (command == CommandEnum::CALC) {
        cmd = std::make_unique<CalcCommand>(tokens, calc);
    } else if (command == CommandEnum::TRANSPOSE) {
        cmd = std::make_unique<TransposeCommand>(tokens, calc);
    } else if (command == CommandEnum::SPLIT) {

    } else if (command == CommandEnum::MERGE) {

    } else if (command == CommandEnum::GEM) {

    } else if (command == CommandEnum::PRINT) {
        cmd = std::make_unique<PrintCommand>(tokens, calc);
    } else if (command == CommandEnum::EXIT) {
        return StateEnum::Exit;
    } else {
        return StateEnum::Help;
    }

    if (cmd->isValid()) {
        cmd->perform();
        return StateEnum::Main;
    }

    return cmd->syntaxError() ? StateEnum::WrongCommand : StateEnum::Main;
}

std::vector<std::string> InputHandler::tokenizeLine(bool toLower) {
    std::string line;
    std::getline(std::cin, line);
    if (toLower) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    }
    std::istringstream iss(line);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};
    return tokens;
}

