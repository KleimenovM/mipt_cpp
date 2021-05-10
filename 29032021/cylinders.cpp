//
// Created by kleim on 3/29/2021.
//

#include <iostream>

int main(){
    int quantity, num = 1;
    double max_mass = 0.;
    std::cin >> quantity;

    for (int i = 0; i < quantity; i++){
        double rad, h, den, mass;

        std::cin >> rad >> h >> den;
        mass = rad * rad * h * den;
        if (mass > max_mass){
            max_mass = mass;
            num = i;
        }
    }

    std::cout << num << std::endl;

    return 0;
}

