//
// Created by User on 4/4/2021.
//

#include <iostream>

int main(){
    int quantity, cur, max = 0, counter = 0;
    std::cin >> quantity;

    for (int i = 0; i < quantity; i++) {
        std::cin >> cur;
        if (i == 0){
            max = cur;
            counter++;
        } else if (cur == max)
            counter++;
        else if (cur > max) {
            max = cur;
            counter = 1;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}
