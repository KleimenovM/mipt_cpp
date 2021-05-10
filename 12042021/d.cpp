//
// Created by kleim on 4/12/2021.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Employee {
    char name[20];
    bool is_male;
    int position_id;
    double salary;
    long int phone_number;
};

bool is_equal_salary(Employee* e, unsigned int n) {
    double male = 0, male_counter = 0, female = 0, female_counter = 0;

    for (int i = 0; i < n; i++){
        if (e[i].is_male) {
            male += e[i].salary;
            male_counter++;
        }
        else {
            female += e[i].salary;
            female_counter++;
        }
    }

    male = male / male_counter;
    female = female / female_counter;

    double min;
    if (male > female)
        min = female;
    else
        min = male;

    double eps = (male - female) / min;

    if (eps < 0)
        eps = -eps;

    if (eps > 0.05)
        return false;
    else
        return true;
}

int main()
{
    Employee stat[7] = {
            {"Alice", false, 130, 7305.855, 5550712},
            {"Bob", false, 130, 9597.154, 5550734},
            {"Charlie", false, 150, 9500.612, 5550988},
            {"Daniel", false, 220, 2065.883, 5550821},
            {"Emma", false, 150, 2030.27, 5550988},
            {"A", true, 111, 2292.599, 8},
            {"A", false, 111, 2024.068, 8}
    };
    cout << is_equal_salary(stat, 7) << endl; // ваша функция должна вернуть true
    return 0;
}

