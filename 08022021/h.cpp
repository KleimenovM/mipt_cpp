#include <iostream>
#include <cmath>

int main()
{
    int k, n, counter = 0, i = 2;
    std::cin >> k;
    n = k;

    while (i < sqrt(k) + 1) {
        if (n % i == 0) {
            n = n / i;
            std::cout << i << std::endl;
            counter++;
        }
        else {
            i++;
            counter = 0;
        }
    }

    if (counter == 0 && int(n) - 1 != 0) std::cout << n << std::endl;
}
