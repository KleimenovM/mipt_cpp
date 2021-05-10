//
// Created by kleim on 3/29/2021.
//

#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    int quantity;
    std::cin >> quantity;

    double rad_sum = 0;
    for (int i = 0; i < quantity; i++){
        double rad;
        std::cin >> rad;
        rad_sum += rad * rad;
    }

    rad_sum = std::pow(rad_sum, 0.5);

    std::cout << std::setprecision(4) << std::fixed << rad_sum << std::endl;

    return 0;
}
