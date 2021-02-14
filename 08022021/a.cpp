#include <iostream>

int main()
{
    int x, y;

    std::cin >> x >> y; // got x and y as integers

    while (x != 0 and y != 0) {
        if (x == y) break;
        else if (x > y) x = x % y;
        else y = y % x;
        // std::cout << x << y << std::endl;
    }

    std::cout << std::max(x, y) << std::endl;

    return 0;
}
