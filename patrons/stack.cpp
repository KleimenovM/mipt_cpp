#include <iostream>

struct Stack{
    int elem;
    Stack *next;
};

Stack *get_data() {
    int quantity;
    std::cin >> quantity;
    Stack *first = nullptr, *cur_node;

    for (int i = 0; i < quantity; i++){
        auto *new_node = new Stack;
        std::cin >> new_node->elem;
        new_node->next = nullptr;

        if (first == nullptr) {
            cur_node = new_node;
            first = new_node;
        }
        else
            cur_node->next = new_node;

        cur_node = new_node;
    }
    return first;
}

int main(){
    Stack *first = get_data();
    return 0;
}
