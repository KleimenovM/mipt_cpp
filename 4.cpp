#include <iostream>
#include <string>

int n;
std::string a = "";

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        a = a + "*";
        std::cout << a << std::endl;
    }

    return 0;
}
