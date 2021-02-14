#include <iostream>

int main()
{
    int num, counter = 0;

    std::cin >> num;
    int maxnum = num;

    while (num != 0) {
        if (num > maxnum) {
            maxnum = num;
            counter = 1;
        }

        else if (num == maxnum) counter++;
        std::cin >> num;
    }

    std::cout << counter << std::endl;

    return 0;
}
