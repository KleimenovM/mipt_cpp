# include <iostream>

struct Stack_elem {
    int value; // last value
    Stack_elem *prev; // pointer to next one
};

int main() {
    Stack_elem *last = nullptr;

    int number;
    std::cin >> number;

    while (number != 0) {
        auto *new_stack = new Stack_elem;
        new_stack->value = number;
        new_stack->prev = nullptr;

        if (last == nullptr)
            last = new_stack;
        else
            new_stack->prev = last;

        new_stack->value = number;
        last = new_stack;
        std::cin >> number;
    }

    Stack_elem *cur;
    while (last != nullptr) {
        std::cout << last->value << std::endl;
        cur = last;
        last = last->prev;
        delete cur;
    }

    return 0;
};