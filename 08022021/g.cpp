#include <iostream>
#include <cmath>

int main()
{
    int a, counter = 1;

    std::cin >> a;

    if (a % 2 == 0) counter = 0;
    else {
        for (int i = 3; i < (sqrt(a) + 2); i += 2) {
            if (a % i == 0) {
                counter = 0;
                break;
            }
        }
    }

    std::cout << counter << std::endl;

    return 0;
}
