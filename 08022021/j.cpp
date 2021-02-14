#include <iostream>
#include <string>

int main()
{
    int num, r;
    std::string babyl = "";
    std::cin >> num;

    r = num % 60;
    for (int i = 0; i < r / 10; i++) babyl += "<";
    for (int i = 0; i < r % 10; i++) babyl += "v";
    num = (num - r) / 60;

    while (num >= 1) {
        babyl = "." + babyl;
        r = num % 60;
        for (int i = 0; i < r % 10; i++) babyl = "v" + babyl;
        for (int i = 0; i < r / 10; i++) babyl = "<" + babyl;
        num = (num - r) / 60;
    }

    std::cout << babyl << std::endl;

    return 0;
}
