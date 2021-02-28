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
    std::cin >> quantity; // defined quantity of operations
    Dwarf *first = nullptr, *memory = nullptr, *cur, *cur_mem;

    for (int i = 0; i < quantity; i++) {
        std::string symbol; // defines type of operation
        std::cin >> symbol;

        if (symbol == "-") {
            auto *new_mem = new Dwarf;
            // "delete" one dwarf
            line_length--;
            new_mem->num = first->num;
            new_mem->next = nullptr;
            if (memory == nullptr) {
                cur_mem = new_mem;
                memory = cur_mem;
            }
            else
                cur_mem->next = new_mem;

            cur_mem = new_mem;
            first = first->next;
        }

        else {
            // add one dwarf
            int num;
            auto *next_dwarf = new Dwarf;
            std::cin >> num;
            line_length++;

            next_dwarf->next = nullptr;
            next_dwarf->num = num;

            if (first == nullptr) {
                cur = next_dwarf;
                first = cur;
            }
            else if (symbol == "*") {
                Dwarf *cur_star;
                // here we add a dwarf to the middle of a line
                cur_star = first;
                for (int j = 0; j < line_length / 2; j++)
                    cur_star = cur_star->next;
                next_dwarf->next = cur_star->next;
                cur_star->next = next_dwarf;
            } else {
                Dwarf *cur_plus;
                // here we add a dwarf to the end of the line
                for (int j = 0; j < line_length; j++)
                    cur_plus = cur_plus->next;
                cur_plus->next = next_dwarf;
            }
        }
    }

    while (memory != nullptr) {
        std::string minus;
        std::cin >> minus;
        if (minus == "-") {
            std::cout << memory->num << std::endl;
            memory = memory->next;
        }
    }

    return 0;
}
