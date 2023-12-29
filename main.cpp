#include <iostream>
#include <locale>   

#include "Header.h"

int main() {

    setlocale(LC_ALL, "RU");

    std::unordered_set<std::string> states = { "1", "2", "3", "4" };
    std::unordered_set<std::string> alphabet = { "a", "b" };
    std::string initialState = "1";
    std::unordered_set<std::string> finalStates = { "4" };
    std::vector<Transition> transitions = {
        { "1", "a", "2" }, { "1", "b", "4" },
        { "2", "a", "1" }, { "2", "b", "3" },
        { "3", "a", "4" }, { "3", "b", "2" },
        { "4", "a", "3" }, { "4", "b", "1" },
    };

    FiniteAutomaton fa(states, alphabet, transitions, finalStates, initialState);

    std::vector<std::string> test1 = { "b", "b", "a" };
    std::cout << "Test 1: ";
    bool result1 = fa.execute(test1);
    std::cout << (result1 ? "Accepted" : "Rejected") << std::endl;

    std::vector<std::string> test2 = { "a", "b", "a", "a", "b" };
    std::cout << "Test 2: ";
    bool result2 = fa.execute(test2);
    std::cout << (result2 ? "Accepted" : "Rejected") << std::endl;

    std::vector<std::string> test3 = { "b", "a", "b", "a", "a", "b" };
    std::cout << "Test 3: ";
    bool result3 = fa.execute(test3);
    std::cout << (result3 ? "Accepted" : "Rejected") << std::endl;
    return 0;
}
