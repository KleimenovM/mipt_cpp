#include <iostream>
#include <string>

int main()
{
    int num, k = 1, counter = 0;

    std::cin >> num;

    while (k <= num) {
        k *= 2;
        if (num == k) {
            counter = 1;
            break;
        }
    }
    if (counter == 0) {
        std::cout << "NO" << std::endl;
    }
    else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}
