//
// Created by kleim on 2/22/2021.
//

#include <iostream>
#include <string>

struct Dwarf {
    Dwarf *next; // refers to the next dwarf in a row
    int num; // defines dwarf's number
};

int main() {
    int quantity, line_length = 0;
    std::cin >> quantity; // defined quantity of dwarves
    Dwarf *first = nullptr;

    for (int i = 0; i < quantity; i++) {
        std::string symbol;

        if (symbol == "-") {
            // "delete" one dwarf
            std::cout << "-";
            line_length--;
        }
        else {
            // add one dwarf
            int num;
            Dwarf *cur, *next;
            std::cin >> num;
            line_length++;

            if (first == nullptr) {
                first->next = nullptr;
                first->num = num;
            }

            if (symbol == "*") {
                // here we add a dwarf to the middle of a line
                std::cout << "*";
            } else {
                // here we add a dwarf to the end of the line
                std::cout << "+";
                for (int j = 0; j < line_length; j++) {
                }
            }
        }
    }

    return 0;
}
