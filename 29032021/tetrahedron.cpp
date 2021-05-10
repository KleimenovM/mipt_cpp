//
// Created by kleim on 3/29/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
    auto *matrix = new double[12];
    for (int i = 0; i < 12; i++)
        std::cin >> matrix[i];

    auto *vec = new double [9];
    for (int j = 3; j < 12; j++)
        vec[j - 3] = matrix[j] - matrix[j % 3];

    double det1 = vec[0] * vec[4] * vec[8] + vec[1] * vec[5] * vec[6] + vec[3] * vec[7] * vec[2];
    double det2 = vec[2] * vec[4] * vec[6] + vec[0] * vec[7] * vec[5] + vec[8] * vec[1] * vec[3];
    double det = (det1 - det2) / 6;

    std::cout << std::setprecision(4) << std::fixed << std::fabs(det) << std::endl;

    delete[] matrix;
    delete[] vec;

    return 0;
}
