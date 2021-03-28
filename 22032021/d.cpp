//
// Created by kleim on 3/22/2021.
//

#include <iostream>
#include <string>

struct Resident {
    std::string name;
    int quality{};
    Resident *next{};
    Resident *prev{};
};

Resident* get_all_the_residents(int guys) {
    Resident *first = nullptr, *cur_res = first;

    for (int i = 0; i < guys; i++) {
        auto *new_res = new Resident;
        std::cin >> new_res->name; /* name - string */
        std::cin >> new_res->quality; /* quality (liar - 0 or knight - 1) */
        new_res->next = nullptr;
        new_res->prev = cur_res;

        if (first == nullptr) {
            new_res->prev = nullptr;
            cur_res = new_res;
            first = cur_res;
        }

        if (i == guys - 1) {
            new_res->next = first; /* locked a cycle */
            first->prev = new_res;
        }

        cur_res->next = new_res;
        cur_res = new_res;
    }
    return first;
}


int main(){
    int guys, days;
    bool news;
    std::cin >> guys;
    std::cin >> news;

    Resident *first = get_all_the_residents(guys), *cur_res = first;

    std::cin >> days;

    for (int i = 0; i < days; i++) {
        if (cur_res->next == cur_res)
            break;

        if (news) {
            if (!cur_res->quality)
                news = !news;
            cur_res = cur_res->next;
        } else {
            if (cur_res->quality){
                if (cur_res == first)
                    first = first->next;
                cur_res->prev->next = cur_res->next; /* knight dies */
                cur_res->next->prev = cur_res->prev;
            } else {
                cur_res->quality = true; /* becomes a knight */
                news = !news;
            }
            cur_res = cur_res->next;
        }
    }

    cur_res = first;
    std::cout << cur_res->name << " " << cur_res->quality << std::endl;
    cur_res = cur_res->next;
    while(cur_res != first) {
        std::cout << cur_res->name << " " << cur_res->quality << std::endl;
        cur_res = cur_res->next;
    }

    return 0;
}