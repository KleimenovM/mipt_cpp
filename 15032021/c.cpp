//
// Created by kleim on 3/15/2021.
//

#include <iostream>
#include <string>
#include "c.h"

int main() {
    int a;
    Stack st;
    std::cin >> a;
    while (a != 0) {
        if (a == -1)
            std::cout << st.pop() << std::endl;
        else if (a == -2) {
            int size;
            std::cin >> size;
            st.resize(size);
        }
        else if (a == -3)
            st.clear();
        else if (a == -4)
            st.shrink_to_fit();
        else
            st.push(a);
        std::cin >> a;
    }
    return 0;
}
