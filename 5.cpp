#include <iostream>
#include <string>

int n;
std::string a = "";

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        a += "*";
    }

    for (int i = n; i > 0; i--) {
         std::cout << a.substr(0, i) << std::endl;
    }

    return 0;
}
