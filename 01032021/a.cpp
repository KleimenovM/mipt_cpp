# include <iostream>

struct Stack_elem {
    int size;
    int value;
    Stack_elem *prev;
};

int main(){
    int number;
    std::cin >> number;
    Stack_elem *last = nullptr;

    while (number != 0) {
        if (number > 0) {
            auto *new_elem = new Stack_elem;
            new_elem->value = number;
            if (last == nullptr) {
                new_elem->size = 1;
                new_elem->prev = nullptr;
                last = new_elem;
            } else {
                new_elem->size = last->size + 1;
                new_elem->prev = last;
            }
            last = new_elem;
        }
        else if (last != nullptr) {
            if (- number < last->value)
                last->value += number;
            else if(last->prev != nullptr) {
                Stack_elem *new_elem;
                new_elem = last;
                last = last->prev;
                delete new_elem;
            }
            else
                last = nullptr;
        }
        std::cin >> number;
    }

    if (last == nullptr){
        std::cout << 0 << std::endl;
        std::cout << -1 << std::endl;
    } else {
        std::cout << last->size << std::endl;
        std::cout << last->value << std::endl;
    }

    Stack_elem *cur;
    while (last != nullptr) {
        cur = last;
        last = last->prev;
        delete cur;
    }

    return 0;
}
