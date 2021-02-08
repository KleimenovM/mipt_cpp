#include <iostream>
#include <string>
#include <cmath>

int x = 0;
int y = 0;
double l = 0;


int main()
{
    std::cin >> x >> y;
    l = std::pow(x*x + y*y, 0.5);
    std::cout << l;
    return 0;
}
