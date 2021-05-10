//
// Created by kleim on 3/29/2021.
//

#include <iostream>
#include <string>

int main(){
    int height, length;
    std::cin >> height;
    std::cin >> length;

    std::string border, middle;

    for (int i = 0; i < length; i++){
        border += "*";
        if (i == 0 || i == length - 1)
            middle += "*";
        else
            middle += " ";
    }

    for (int j = 0; j < height; j++){
        if (j == 0 || j == height - 1)
            std::cout << border << std::endl;
        else
            std::cout << middle << std::endl;
    }

    return 0;
}

