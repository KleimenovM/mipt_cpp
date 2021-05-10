//
// Created by kleim on 3/29/2021.
//

#include <iostream>
#include <string>

struct Goblin{
    bool if_coin;
    Goblin *next;
};

Goblin *get_data(int quantity) {
    Goblin *first = nullptr, *cur_node = nullptr;

    for (int i = 0; i < quantity; i++){
        auto *new_node = new Goblin;
        new_node->if_coin = false;
        new_node->next = nullptr;

        if (first == nullptr) {
            first = new_node;
        }
        else
            cur_node->next = new_node;

        cur_node = new_node;
    }
    if (cur_node != nullptr)
        cur_node->next = first; // closed the goblin-loop

    return first;
}

int if_no(Goblin *first, int goblin_quantity){
    int breaker = 0;
    Goblin *loop_goblin = first;
    for(int j = 0; j < goblin_quantity; j++){
        // if goblin has no coins
        if (!loop_goblin->if_coin)
            breaker++;
        loop_goblin = loop_goblin->next;
    }
    return breaker;
}

int main(){
    // Purse initialization
    int purses_quantity;
    std::cin >> purses_quantity;
    auto *purses = new int[purses_quantity];

    for(int i = 0; i < purses_quantity; i++){
        int val;
        std::cin >> val;
        purses[i] = val;
    }

    // Goblin initialization
    int goblin_quantity;
    std::cin >> goblin_quantity;
    Goblin *first = get_data(goblin_quantity);

    // Start wasting money!
    Goblin *cur_goblin = first;
    int breaker = 0;
    for(int i = 0; i < purses_quantity; i++){ // while purses exist
        cur_goblin = cur_goblin->next;

        // while coins in purses exist
        while(purses[i] > 0){
            cur_goblin->if_coin = true;

            // shift
            for(int j = 0; j < i + 2; j++)
                cur_goblin = cur_goblin->next;

            purses[i]--;

            // check whether there are any goblins without coins left
            breaker = if_no(first, goblin_quantity);

            if (breaker == 0)
                break;
        }
        breaker = if_no(first, goblin_quantity);
        if (breaker == 0)
            break;
    }
    if (breaker == 0){
        for(int i = 0; i < purses_quantity; i++)
            breaker += purses[i];
        std::cout << "YES " << breaker << std::endl;
    }
    else
        std::cout << "NO " << breaker << std::endl;

    // clean everything

    delete[] purses;

    cur_goblin = first;
    Goblin *next_goblin;
    for (int i = 0; i < goblin_quantity; i++) {
        next_goblin = cur_goblin->next;
        delete cur_goblin;
        cur_goblin = next_goblin;
    }

    return 0;
}

