//
// Created by User on 4/4/2021.
//

#include <iostream>
#include <cmath>

int main(){
    double accel1, vel2, dist;
    std::cin >> accel1 >> vel2 >> dist;

    double time1, time2;
    time1 = std::sqrt(2 * dist / accel1);
    time2 = dist / vel2;

    if (time1 - time2 >= 0.001)
        std::cout << 2 << std::endl;
    else
        std::cout << 1 << std::endl;

    return 0;
}
