#include <iostream>

int main() {
    int a, b, c, d, x;
    int mark = 2;
    std::cin >> a >> b >> c >> d >> x;


    bool first = (a + x == b);
    bool second = (c * x == d);

    if (first && second)
        mark = 5;
    else if (first || second)
        mark = 4;
    else if (x == 1024)
        mark = 3;

    std::cout << mark << std::endl;

    return 0;
}
