//
// Created by kleim on 3/29/2021.
//

#include <iostream>
#include <string>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::string disk, handle;

    for (int i = 0; i < n; i++)
        handle += "=";
    for (int j = 0; j < m; j++)
        disk += "|";

    std::cout << disk + handle + disk << std::endl;

    return 0;
}
