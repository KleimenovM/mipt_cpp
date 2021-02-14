#include <iostream>

int main()
{
    int num, maxnum = 0;

    std::cin >> num;

    while (num != 0) {
        if (num % 2 == 0 && num > maxnum) {
            maxnum = num;
        }
        std::cin >> num;
    }

    std::cout << maxnum << std::endl;

    return 0;
}
