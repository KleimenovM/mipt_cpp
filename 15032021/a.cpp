#include <iostream>
#include <string>

class Stack
{
public:
    Stack ();  /* constructor */
    ~Stack ();  /* destructor */
    void push(int elem ); /* method */
    int pop ();
    void resize(int capacity_increase_to ); /* increase capacity */
    void shrink_to_fit (); /* free unused memory */
    void clear (); /* remove all elements, leave capacity the same */

private:
    int *content;
    int size;
    int capacity;
};

Stack::Stack() {
    this->content = new int[32];
    this->size = 0;
    this->capacity = 32;
}

Stack::~Stack() {
    delete this->content;
}

void Stack::push(int elem) {
    if (this->size == this->capacity)
        this->resize(this->capacity * 2);

    this->content[size] = elem;
    this->size++;
}

int Stack::pop() {
    if (this->size == 0) {
        std::cout << "Stack is empty. Value is 0" << std::endl;
        return 0;
    }
    this->size--;
    int a = this->content[this->size];
    return a;
}

void Stack::resize(int capacity_increase_to) {
    if (capacity_increase_to < this->capacity)
        std::cout << "You cannot decrease capacity with this function" << std::endl;
    else {
        int *new_mem = new int[capacity_increase_to]; /* new content */
        for (int i = 0; i < this->size; i++)
            new_mem[i] = this->content[i]; /* relocate */
        delete this->content; /* clear memory */

        this->content = new_mem;
        this->capacity = capacity_increase_to; /* capacity increases */
    }
}

void Stack::shrink_to_fit() {
    int *new_mem = new int[this->size]; /* new smaller content */
    for (int i = 0; i < this->size; i++)
        new_mem[i] = this->content[i];
    delete this->content;

    this->content = new_mem;
    this->capacity = this->size; /* capacity decreases */
}

void Stack::clear() {
    delete this->content; /* clear memory */
    this->size = 0;
}

int main() {
    int a;
    Stack st;
    std::cin >> a;
    while (a != 0) {
        if (a == -1)
            std::cout << st.pop() << std::endl;
        else if (a == -2) {
            int size;
            std::cin >> size;
            st.resize(size);
        }
        else if (a == -3)
            st.clear();
        else if (a == -4)
            st.shrink_to_fit();
        else
            st.push(a);
        std::cin >> a;
    }
    return 0;
}
