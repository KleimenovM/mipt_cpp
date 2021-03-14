//
// Created by User on 3/14/2021.
//

// программа про скобочки

#include <iostream>
#include <string>

struct Bracket {
    int value;
    Bracket *prev;
};

int bracket_to_integer(const std::string& br) {
    std::string brs [6] = {"(", ")", "{", "}", "[", "]"};
    int nums [6] = {1, -1, 2, -2, 3, -3};
    int num = 0;
    for (int i = 0; i < 6; i++) {
        if (br == brs[i])
            num = nums[i];
    }
    return num;
}

int main(){
    std::string br;
    std::cin >> br;
    Bracket *last = nullptr, *current = nullptr;
    while (br != ".") {
        if (bracket_to_integer(br) == 0)
            continue;

        auto *new_br = new Bracket;
        new_br->prev = current;
        new_br->value = bracket_to_integer(br);

        std::cin >> br;

        if (last == nullptr) {
            current = new_br;
            last = current;
        }
        else {

        }
    }
    return 0;
}