//
// Created by kleim on 4/12/2021.
//

#include <iostream>
using std::cout;
using std::cin;
using std::boolalpha;

void reverse_memories(int* begin, unsigned int n){
    auto *reverse = new int [n];
    for (int i = 0; i < n; i++)
        reverse[i] = begin[n - i - 1];
    for (int j = 0; j < n; j++)
        begin[j] = reverse[j];
}

int main()
{
    int memories[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    reverse_memories(memories, 10);

    for (unsigned int i = 0; i < 10; i++)
        cout << memories[i] << " ";

    cout << std::endl; // должно вывести: 10 9 8 7 6 5 4 3 2 1

    return 0;
}