//
// Created by kleim on 3/22/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

bool define_int(double num){
    double delta = num - round(num);
    if (std::fabs(delta) < 0.0000001)
        return true;
    return false;
}

void print_correct(double num, int n){
    std::string end_line = " ";
    if (n == 1)
        end_line = "\n";

    double delta = num - round(num);
    if (std::fabs(delta) < 0.00000001)
        std::cout << std::setprecision(1) << std::fixed << num << end_line;
    else if (std::fabs(10 * num - round(10 * num)) < 0.0000001)
        std::cout << std::setprecision(1) << std::fixed << num << end_line;
    else if (std::fabs(100 * num - round(100 * num)) < 0.0000001)
        std::cout << std::setprecision(2) << std::fixed << num << end_line;
    else
        std::cout << std::setprecision(3) << std::fixed << num << end_line;
}

int main(){
    long int counter = 0;
    double x, sum = 0, sq_sum = 0, average, sq_average;

    std::cin >> x;

    while(x != 0) {
        sum += x;
        sq_sum += x * x;
        counter++;

        std::cin >> x;
    }

    if (counter == 0) {
        average = 0.0;
        sq_average = 0.0;
    } else {
        average = sum / counter;
        sq_average = sq_sum / counter - average * average;
    }

    print_correct(average, 0);
    print_correct(sq_average, 1);

    return 0;
}