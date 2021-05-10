//
// Created by kleim on 3/29/2021.
//

#include <iostream>
#include <string>

struct Carriage{
   int normal_passengers;
   int false_passengers;
   Carriage *next;
};

class Train{
public:
    int length;
    int conductor_stop;
    int capacity;
    Carriage *first;

    void fill_train();
    void refill_train() const;
    void print_train();

    Train();
    ~Train();
};

Train::Train() {
    this->conductor_stop = 0;
    this->capacity = 0;
    this->first = nullptr;
    this->length = 0;
}

Train::~Train() {
    Carriage *cur_car = this->first, *new_car;

    for(int i = 0; i < length; i++){
        new_car = cur_car->next;
        delete cur_car;
        cur_car = new_car;
    }
}

void Train::fill_train() {
    this->conductor_stop = this->length / 2;
    Carriage *cur_car = this->first;
    for(int i = 0; i < this->length; i++){
        int normal, wrong;
        std::cin >> normal >> wrong;

        auto *next_car = new Carriage;
        next_car->next = nullptr;
        next_car->normal_passengers = normal;
        next_car->false_passengers = wrong;

        if (this->first == nullptr){
            cur_car = next_car;
            this->first = cur_car;
        }

        cur_car->next = next_car;
        cur_car = next_car;
    }
    std::cin >> this->capacity;
}

void Train::refill_train() const {
    Carriage *cur_car = this->first;
    int wrong_p = 0;
    // gather all wrong passengers together
    for (int i = 0; i < this->conductor_stop; i++){
        wrong_p += cur_car->false_passengers;
        cur_car->false_passengers = 0;
        cur_car = cur_car->next;
    }

    for (int i = this->conductor_stop; i < this->length; i++){
        int excess = cur_car->false_passengers + cur_car->normal_passengers - this->capacity;

        if (excess > 0) {
            wrong_p += excess;
            cur_car->false_passengers -= excess;
        }

        int free_seats = this->capacity - (cur_car->false_passengers + cur_car->normal_passengers);

        while (wrong_p > 0 && free_seats > 0) {
            cur_car->false_passengers++;
            wrong_p--;
            free_seats--;
        }

        if (i != this->length - 1)
            cur_car = cur_car->next;
    }

    cur_car->false_passengers += wrong_p; // after reaching the last carriage
}

void Train::print_train() {
    Carriage *cur_car = this->first;
    for (int i = 0; i < this->length; i++) {
        std::cout << cur_car->normal_passengers << " " << cur_car->false_passengers << std::endl;
        cur_car = cur_car->next;
    }
}

int main(){
    int length;
    std::cin >> length;

    Train train;
    train.length = length;
    train.fill_train();

    train.refill_train(); // reorganize

    train.print_train();

    return 0;
}