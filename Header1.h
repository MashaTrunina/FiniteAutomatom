#pragma once
#include <string>

struct Transition {
    std::string currentState;
    std::string input;
    std::string nextState;
};
