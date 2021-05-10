//
// Created by kleim on 4/12/2021.
//

#include <iostream>

int main(){
    int size_x, size_y;
    int num;

    std::cin >> size_x >> size_y;
    std::cin >> num;

    int *coordinates = new int[2*num];

    for (int i = 0; i < 2 * num; i++){
        int a;
        std::cin >> a;
        coordinates[i] = a;
    }

    int counter = 0;
    for (int i = 0; i < 2*num; i+=2){
        for (int j = 0; j < 2*num; j+=2){
            if (i == j)
                continue;
            if (coordinates[i] == coordinates[j])
                counter++;
            if (coordinates[i + 1] == coordinates[j + 1])
                counter++;
        }
    }

    std::cout << counter / 2 << std::endl;

    return 0;
}
