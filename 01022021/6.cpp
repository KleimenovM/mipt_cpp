#include <iostream>
#include <string>

int n;
std::string a, b;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        a += "*";
    }

    for (int i = 0; i < n; i += 2) {
        std::cout << b + a.substr(0, n-i) << std::endl;
        b += " ";
    }

    return 0;
}
