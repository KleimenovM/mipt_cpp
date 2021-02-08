#include <iostream>
#include <string>

int n;
std::string a = "*";

int main()
{
    std::cin >> n;

    for (int i = 1; i < n; i++) {
        a += "*";
    }

    for (int i = 1; i < n+1; i++) {
        std::cout << a << std::endl;
    }
    return 0;
}
