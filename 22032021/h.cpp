//
// Created by User on 3/28/2021.
//

#include <iostream>

int main(){
    int quantity, memory = 0;
    std::cin >> quantity;
    auto *slippers = new int [quantity];

    for (int i = 0; i < quantity; i++)
        std::cin >> slippers[i];

    for (int i = 0; i < quantity; i++) {
        if (slippers[i] > 0)
            continue;
        for (int j = i + 1; j < quantity; j++) {
            if (slippers[i] + slippers[j] == 0){
                if (memory == 0 || j - i < memory)
                    memory = j - i;
                else
                    continue;
            }
        }
    }

    std::cout << memory << std::endl;

    return 0;
}
