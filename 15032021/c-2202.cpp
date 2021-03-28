//
// Created by kleim on 3/15/2021.
//

#include <iostream>

struct Man{
    int value;
    Man *next;
    Man *prev;
};

Man *organize() {
    int quantity;
    std::cin >> quantity;
    Man *first = nullptr, *cur_man;
    cur_man = first;

    for (int i = 1; i < quantity + 1; i++) {
        auto *new_man = new Man;
        new_man->value = i;
        if (first == nullptr) {
            cur_man = new_man;
            cur_man->next = nullptr;
            cur_man->prev = nullptr;
            first = cur_man;
        } else {
            new_man->prev = cur_man;
            cur_man->next = new_man;
        }
    }
    cur_man->next = first;
    first->prev = cur_man;
    return first;
}

int remove(Man *first){
    int k, least;
    std::cin >> k;
    Man *current;
    current = first;

    while (true) {
        least = current->value;
        int a = 0;
        for (int i = 1; i < k + 1; i++)
            if (i == k) {
                if (current == first) {
                    current = first->next;
            }
        }
        if (current->prev == nullptr && current->next == nullptr)
            break;
    }
    return least;
}

int main() {
    Man *first = organize();
    std::cout << remove(first) << std::endl;
    return 0;
}
