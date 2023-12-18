#include <iostream>
#include <locale>   

#include "Header.h"

int main() {

    setlocale(LC_ALL, "RU");

    // Пример использования конструктора
    std::unordered_set<std::string> states = { "1", "2", "3", "4" };
    std::unordered_set<std::string> alphabet = { "100", "sqrt", "2+2", "problems" };

    // Устанавливаем начальное состояние "1"
    std::string initialState = "1";

    std::unordered_set<std::string> finalStates = { "4" };

    // Вектор правил переходов
    std::vector<Transition> transitions = {
        { "1", "100", "1" },{ "1", "sqrt", "2" }, { "1", "problems", "3" },{ "1", "2+2", "4" },
        { "2", "100", "1" }, { "2", "sqrt", "2" }, { "2", "problems", "3" },{ "2", "2+2", "4" },
        { "3", "100", "1" },{ "3", "sqrt", "2" },{ "3", "problems", "3" },{ "3", "2+2", "4" },
        { "4", "100", "1" },{ "4", "sqrt", "2" },{ "4", "problems", "3" },{ "4", "2+2", "4" },
    };

    FiniteAutomaton fa(states, alphabet, transitions, finalStates, initialState);

    // проверка строки для алфавита 
    std::vector<std::string> test = { "100", "sqrt", "problems", "2+2" };
    std::string input;
    for (const std::string& str : test) {
        input += str;
    }
    bool result = fa.execute(test);

    // вывод 
    std::cout << "Строка " << (result ? "принята" : "отклонена") << " автоматом" << std::endl;

    return 0;
}
