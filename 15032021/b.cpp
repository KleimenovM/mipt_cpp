//
// Created by kleim on 3/15/2021.
//

#include <iostream>
#include <string>

struct Node { /* List element */
    int elem;
    Node* next;
    Node* prev;
};

class List { /* list itself */
public:
    List(); /* constructor */
    ~List(); /* destructor */
    void push_back(int elem); /* method */
    int pop_back();

    void push_front(int elem);

    int pop_front();

    void push_at(unsigned int position, int elem);

    int pop_at(unsigned int position);

    unsigned int size() const; /* just return current size */
    void clear(); /* remove all elements from list */

private:
    Node *first;
    Node *last;
    int list_size;
};

List::List() {
    this->first = nullptr;
    this->last = nullptr;
    list_size = 0;
}

List::~List() {
    this->clear();
}

void List::push_back(int elem) {
    auto *new_node = new Node;

    new_node->prev = this->last;
    new_node->next = nullptr; /* ? */
    new_node->elem = elem;

    this->list_size++;

    if (this->last == nullptr) {
        this->last = new_node;
        this->first = this->last;
    } else {
        this->last->next = new_node;
        this->last = new_node;
    }
}

int List::pop_back() {
    if (last == nullptr) {
        std::cout << "This list is empty" << std::endl;
        return 0;
    }
    int a;
    a = this->last->elem;

    this->last = this->last->prev;
    delete this->last->next;
    this->last->next = nullptr;

    this->list_size--;
    return a;
}

void List::push_front(int elem) {
    auto *new_node = new Node;

    new_node->next = this->first;
    new_node->prev = nullptr;
    new_node->elem = elem;

    this->list_size++;

    if (this->first == nullptr) {
        this->first = new_node;
        this->last = this->first;
    } else {
        this->first->prev = new_node;
        this->first = new_node;
    }
}

int List::pop_front() {
    if (first == nullptr) {
        std::cout << "This list is empty" << std::endl;
        return 0;
    }
    int a;
    a = this->first->elem;

    this->first = this->first->next;
    delete this->first->prev;
    this->first->prev = nullptr;

    this->list_size--;
    return a;
}

void List::push_at(unsigned int position, int elem) {
    auto *new_node = new Node;
    Node *cur_node = this->first; /* current node for "FOR"-loop */
    new_node->elem = elem; new_node->prev = nullptr; new_node->next = nullptr;

    if (position > this->list_size)
        std::cout << "This list is not long enough" << std::endl;
    else if (this->first == nullptr) {
        this->first = new_node;
        this->last = this->first;
        list_size++;
    }
    else {
        for (int i = 0; i < position; i++)
            cur_node = cur_node->next;

        if (cur_node == nullptr) /* got to the end */
            this->push_back(elem);
        else {
            new_node->prev = cur_node->prev;
            new_node->next = cur_node;
        }

        if (new_node->prev != nullptr)
            new_node->prev->next = new_node;
        if (new_node->next != nullptr)
            new_node->next->prev = new_node;

        list_size++;
    }
}

int List::pop_at(unsigned int position) {
    if (position > this->list_size - 1) {
        std::cout << "This list is not long enough" << std::endl;
        return 0;
    }

    Node *cur_node = this->first; /* current node for "FOR"-loop */
    int a;

    for (int i = 0; i < position; i++)
        cur_node = cur_node->next;

    a = cur_node->elem;
    if (cur_node->prev == nullptr)
        cur_node->next->prev = cur_node->prev;
    else if (cur_node->next == nullptr)
        cur_node->prev->next = cur_node->next;
    else {
        cur_node->prev->next = cur_node->next;
        cur_node->next->prev = cur_node->prev;
    }
    delete cur_node;
    list_size--;
    return a;
}

unsigned int List::size() const {
    return this->list_size;
}

void List::clear() {
    Node *cur_node = first;
    for (int i = 0; i < this->list_size; i++) {
        cur_node = cur_node->next;
        delete cur_node;
    }
}

int main() {
    return 0;
}
