//
// Created by kleim on 4/5/2021.
//

#include <fstream>
#include <iostream>
#include <chrono>
#include <cstring>

struct Node{
    int value;
    Node *next;
    Node *prev;
};

class List{
public:
    int length;
    Node *first;
    Node *middle;
    Node *last;

    List();
    ~List();

    void push_back(int elem);
    void push_front(int elem);
    void push_mid(int elem);
};

List::List() {
    this->length = 0;
    this->first = nullptr;
    this->middle = nullptr;
    this->last = nullptr;
}

List::~List() {
    Node *cur_node = this->first;
    Node *next_node;
    for (int i = 0; i < this->length - 1; i++){
        next_node = cur_node->next;
        delete cur_node;
        cur_node = next_node;
    }
}

void List::push_back(int elem) { // to the end
    auto *new_node = new Node;
    new_node->next = nullptr;
    new_node->prev = this->last;
    new_node->value = elem;
    if (this->length == 0){
        this->first = new_node;
        this->middle = new_node;
    } else {
        this->last->next = new_node;
        // this->first = const;
        if (this->length % 2 == 0)
            this->middle = this->middle->next;
    }
    this->last = new_node;
}

void List::push_front(int elem) { // to the beginning
    auto *new_node = new Node;
    new_node->next = this->first;
    new_node->prev = nullptr;
    new_node->value = elem;
    if (this->length == 0){
        this->middle = new_node;
        this->last = new_node;
    } else {
        this->first->prev = new_node;
        // this->last = const;
        if (this->length % 2 == 0 && this->length != 2)
            this->middle = this->middle->prev;
    }
    this->first = new_node;
    this->length++;
}

void List::push_mid(int elem) { // to the middle
    auto *new_node = new Node;
    new_node->next = this->middle;
    new_node->prev = this->middle->prev;
    new_node->value = elem;
    this->middle->prev = new_node;
    this->middle = new_node;
    this->length++;
}

int main(){
    std::ofstream fout("results.csv");
    for (int N = 500000; N < 100000000; N += 1600000) {
        std::cout << "N = " << N << std::endl;
        List list;
        for (int i = 0; i < N; i++) {
            list.push_front(i);
        }
         /*
        Node *cur_node = list.first;
        for(int i = 0; i < list.length; i++){

        }*/

        auto start = std::chrono::high_resolution_clock::now();
        list.push_mid(42);
        auto end = std::chrono::high_resolution_clock::now();
        auto n_sec = end - start;
        fout << N << "," << n_sec.count() << std::endl;
        std::cout << "N = " << N << " done" << std::endl;
    }
    fout.close();
    std::cout << "end" << std::endl;

    return 0;
}
