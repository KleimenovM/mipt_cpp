#include <iostream>

int main() {
    int a, b; // инициализируем целые a и b
    // int *pa = &a, *pb = &b; // инициализируем указатели и присваиваем им значения адресов a и b

    std::cin >> a;
    std::cin >> b;

    std::cout << do_some_awesome_work(&a, &b) << std::endl;

    return 0;
}


