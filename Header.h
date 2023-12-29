#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "Header1.h"

class FiniteAutomaton {
public:
    FiniteAutomaton(
        std::unordered_set<std::string> states,
        std::unordered_set<std::string> alphabet,
        std::vector<Transition> transitions,
        std::unordered_set<std::string> finalStates,
        std::string initialState);

    bool execute(std::vector<std::string> input) const;

private:
    std::unordered_set<std::string> states_;
    std::unordered_set<std::string> alphabet_;
    std::vector<Transition> transitions_;
    std::unordered_set<std::string> finalStates_;
    std::string initialState_;
};
