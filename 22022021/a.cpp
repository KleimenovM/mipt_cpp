//
// Created by kleim on 2/22/2021.
//

#include <iostream>
#include <cstdint>

struct Node {
    int64_t value;
    Node *next;
};

Node *mergeLists(Node *first_node, Node *second_node) {
    // first_node - указатель на начало первого списка
    // second_node - указатель на начало второго списка
    Node *result = nullptr, *cur_node;
    // result - указатель на 1й элемент нового массива
    // new node - указатель на текущий элемент нового списка

    while (first_node != nullptr || second_node != nullptr) {
        Node *next_node;
        if (first_node == nullptr) {
            next_node = second_node;
            second_node = second_node->next;
        } else if (second_node == nullptr) {
            next_node = first_node;
            first_node = first_node->next;
        } else if (first_node->value > second_node->value) {
            next_node = second_node;
            second_node = second_node->next;
        } else {
            next_node = first_node;
            first_node = first_node->next;
        }

        next_node->next = nullptr; // по умолчанию обнуляем ссылку нового элемента

        if (result == nullptr) {
            // если первый элемент не существует
            cur_node = next_node; // предыдущего элемента не существует, поэтому объявим его предыдущим
            result = cur_node; // тогда result равен предыдущему
        } else
            cur_node->next = next_node; // новая итерация цикла

        cur_node = next_node;
    }


    return result;
}

int main(){
    int n, m;
    int64_t num;
    Node *first = nullptr, *second = nullptr, *cur_node = nullptr;

    std::cin >> n;
    for (int i = 0; i < n; i++){
        Node *new_node = new Node;
        std::cin >> num;
        new_node->value = num;
        new_node->next = nullptr;

        if (first == nullptr)
            first = new_node;
        else
            cur_node->next = new_node;

        cur_node = new_node;
    }

    std::cin >> m;
    for (int i = 0; i < m; i++){
        Node *new_node = new Node;
        std::cin >> num;
        new_node->value = num;
        new_node->next = nullptr;

        if (second == nullptr)
            second = new_node;
        else
            cur_node->next = new_node;

        cur_node = new_node;
    }

    Node *result;
    result = mergeLists(first, second);

    cur_node = result;
    Node *next_node;
    for (int i = 0; i < n + m; i++) {
        next_node = cur_node->next;
        std::cout << cur_node->value << std::endl;
        cur_node = next_node;
    }

    for (int i = 0; i < n + m; i++) {
        next_node = cur_node->next;
        delete cur_node;
        cur_node = next_node;
    }

    return 0;
}
