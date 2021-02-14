#include <iostream>
#include <string>

int main()
{
    int vel, money = 0, counter = 0;
    std::string num;

    std::cin >> vel >> num;

    if (num == "A999AA") {
        std::cout << 0 << std::endl;
        return 0;
    }

    while (num != "A999AA"){
        if (vel > 60) {
            if (num[1] == num[2]) counter++;
            if (num[2] == num[3]) counter++;
            if (num[3] == num[1]) counter++;

            if (counter == 0) money += 100;
            else if (counter == 1) money += 500;
            else money += 1000;
        }

        counter = 0;
        std::cin >> vel >> num;
    }

    std::cout << money << std::endl;

    return 0;
}
