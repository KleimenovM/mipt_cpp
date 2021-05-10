//
// Created by kleim on 4/12/2021.
//

#include <iostream>
#include <cmath>

int main(){
    double m, k, f;
    std::cin >> m >> k >> f;

    std::cout << std::ceil(m * k * 9.8 / f) << std::endl;

    return 0;
}
