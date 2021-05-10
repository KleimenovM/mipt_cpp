//
// Created by kleim on 3/29/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
    double h, vel, time, x;
    std::cin >> h >> vel;

    time = pow((2 * h / 9.81), 0.5);

    x = vel * time;

    std::cout << std::setprecision(4) << std::fixed << x << std::endl;

    return 0;
}
