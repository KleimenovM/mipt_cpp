//
// Created by kleim on 3/29/2021.
//

#include <iostream>
#include <string>

int **define_matrix(int len){
    auto **matrix = new int*[len];
    for (int i = 0; i < len; i++)
        matrix[i] = new int[len];
    return matrix;
}

void clear_matrix(int **matrix, int len){
    for (int i = 0; i < len; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main(){
    int quantity;
    std::cin >> quantity;

    auto matrix1 = define_matrix(quantity);
    auto matrix2 = define_matrix(quantity);

    for (int i = 0; i < quantity; i++){
        for (int j = 0; j < quantity; j++)
            std::cin >> matrix1[i][j]; // by rows
    }

    for (int i = 0; i < quantity; i++){
        for (int j = 0; j < quantity; j++)
            std::cin >> matrix2[j][i]; // by columns
    }

    for (int i = 0; i < quantity; i++){
        for (int j = 0; j < quantity; j++) {
            int value = 0;
            for(int k = 0; k < quantity; k++){
                value += matrix1[i][k] * matrix2[j][k];
            }
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    clear_matrix(matrix1, quantity);
    clear_matrix(matrix2, quantity);

    return 0;
}

