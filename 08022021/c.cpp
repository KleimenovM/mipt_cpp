#include <iostream>
#include <string>

int main()
{
    int num, k = 0;

    std::cin >> num;

    while (num != 0) {
        if (num % 2 == 0) {
            k = k + 1;
        }
        std::cin >> num;
    }

    std::cout << k << std::endl;

    return 0;
}
