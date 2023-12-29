#include <iostream>
#include <locale>   

#include "Header.h"

int main() {
    std::unordered_set<std::string> states = { "1", "2", "3", "4" };
    std::unordered_set<std::string> alphabet = { "a", "b" };
    std::string initialState = "1";
    std::unordered_set<std::string> finalStates = { "4" };
    std::vector<Transition> transitions = {
        { "1", { "a" }, "2" }, { "1", { "b" }, "4" },
        { "2", { "a" }, "1" }, { "2", { "b" }, "3" },
        { "3", { "a" }, "4" }, { "3", { "b" }, "2" },
        { "4", { "a" }, "3" }, { "4", { "b" }, "1" },
    };

    FiniteAutomaton fa(states, alphabet, transitions, finalStates, initialState);

       while (attempts < 3) {
        std::cout << "Enter a string ): ";
        std::string input;
        std::getline(std::cin, input);

        std::cout << "Result: ";
        bool result = fa.acceptsString(input);
        std::cout << (result ? "Accepted" : "Rejected") << std::endl;

        attempts++;

        if (attempts == 3) {
            break;
        }
    }

    return 0;
}
