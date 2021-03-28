#include <iostream>
#include <string>

int main(){
    int size;
    std::cin >> size;
    auto *matrix = new int [size * size];

    for (int i = 0; i < size * size; i++){
        std::cin >> matrix[i];
    }

    for (int j = 0; j < size; j++) {
        for(int k = size * (size - 1); k >= 0; k-=size)
            std::cout << matrix[j + k] << " ";
        std::cout << std::endl;
    }

    return 0;
}