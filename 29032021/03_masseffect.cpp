//
// Created by User on 4/4/2021.
//

#include <iostream>
#include <string>

int main(){
    int length;
    std::cin >> length;

    auto *line = new int[length];

    for (int i = 0; i < length; i++){
        int num;
        std::cin >> num;
        line[i] = num;
    }

    int first = length / 2;

    for(int i = 0; i < length; i++){
        int odd, cur;
        if (i % 2 == 0)
            odd = 1;
        else
            odd = -1;

        first += odd * i;

        std::cout << line[first] << " ";
    }
    std::cout << std::endl;

    delete[] line;

    return 0;
}