#include "Header.h"

FiniteAutomaton::FiniteAutomaton(
    std::unordered_set<std::string> states,
    std::unordered_set<std::string> alphabet,
    std::vector<Transition> transitions,
    std::unordered_set<std::string> finalStates,
    std::string initialState)
    : states_(states), alphabet_(alphabet),
    transitions_(transitions), finalStates_(finalStates), initialState_(initialState) {}

bool FiniteAutomaton::execute(std::vector<std::string> input) const {
    std::string currentState = initialState_;
    for (std::string c : input) {
        std::string inputStr = c;
        if (alphabet_.count(inputStr) == 0) {
            return false;
        }
        bool transitionFound = false;
        for (const Transition& transition : transitions_) {
            if (transition.currentState == currentState && transition.input == inputStr) {
                currentState = transition.nextState;
                transitionFound = true;
                break;
            }
        }
    }
    return finalStates_.count(currentState) != 0;
}