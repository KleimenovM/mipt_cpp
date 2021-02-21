#include <iostream>

int main()
{
    int n, average = 0, sum = 0;

    std::cin >> n;

    int *line = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> line[i];
        average += line[i];
    }

    average /= n;

    for (int i = 0; i < n; i++) {
        if (line[i] > average)
            sum += line[i];
    }

    delete []line;

    std::cout << sum << std::endl;

    return 0;
}
