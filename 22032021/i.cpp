//
// Created by User on 3/28/2021.
//

#include <iostream>
#include <string>

class List{
public:
    int size;
    int *content;
    int capacity;

    List ();  /* constructor */
    ~List ();  /* destructor */

    void get_new_one(int elem);

    void shrink();

    void sort();
};

List::List() {
    this->size = 0;
    this->content = new int [16];
    this->capacity = 16;
}

List::~List() {
    this->size = 0;
    this->shrink();
}

void List::get_new_one(int elem) {
    this->size++;
    if (this->size > this->capacity) {
        this->capacity *= 2;
        auto list = new int [this->capacity];
        for (int i = 0; i < this->size; i++)
            list[i] = this->content[i];
        this->content = list;
    }
    this->content[this->size - 1] = elem;
}

void List::shrink() {
    auto list = new int [this->size];
    for (int i = 0; i < this->size; i++)
        list[i] = this->content[i];
    this->content = list;
}

void List::sort() {
    this->shrink(); /* recreate to normal size */
    for (int i = 0; i < this->size; i++) {
        for (int j = i; j < this->size; j++) {
            if (this->content[i] > this->content[j]){
                int tmp = this->content[i];
                this->content[i] = this->content[j];
                this->content[j] = tmp;
            }
        }
    }
}

int main(){
    std::string cur_token;
    int num;
    List odd, even;

    // std::cin >> cur_token;

    while (std::cin >> cur_token) {
        num = std::stoi(cur_token);

        if (num % 2 == 0)
            even.get_new_one(num);
        else
            odd.get_new_one(num);
    }

    for (int i = 0; i < even.size; i++)
        std::cout << even.content[i] << " ";
    for (int j = 0; j < odd.size; j++)
        std::cout << odd.content[j] << " ";
    std::cout << std::endl;

    even.sort();
    odd.sort();

    for (int i = 0; i < even.size; i++)
        std::cout << even.content[i] << " ";
    for (int j = 0; j < odd.size; j++)
        std::cout << odd.content[j] << " ";

    std::cout << std::endl;

    return 0;
}