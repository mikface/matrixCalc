//
// Created by Mikuláš on 22. 5. 2018.
//

#include "Command.h"
#include "../matrix/IdentityMatrix.h"

Command::Command(const std::vector<std::string> &commandTokens, const std::shared_ptr<Calculator> &calculator) {
    calc = calculator;
    tokens = commandTokens;
    valid = false;
    showSyntaxError = true;
}

bool Command::isValid() const {
    return valid;
}

bool Command::syntaxError() const {
    return showSyntaxError;
}

Command::~Command() {

}

