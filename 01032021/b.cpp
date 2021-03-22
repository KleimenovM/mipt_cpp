//
// Created by kleim on 3/1/2021.
//

#include <iostream>
#include <string>

struct Node {
    int value;
    Node *prev;
};

int main(){
    std::string val;
    Node *cur_node = nullptr;

    std::cin >> val;

    std::string cur_token;

    while (true) {
        if (val != "+" && val != "*" && val != "-" && val != "/") {
            if (std::stoi(val) == 0)
                break;
            auto *new_node = new Node;
            new_node->prev = cur_node;
            new_node->value = std::stoi(val);
            cur_node = new_node;
        }

        else {
            int a, b, res;
            a = cur_node->value;
            cur_node = cur_node->prev;
            b = cur_node->value;
            cur_node = cur_node->prev;

            if (val == "+")
                res = b+a;
            else if (val == "-")
                res = b-a;
            else if (val == "*")
                res = b*a;
            else if (val == "/")
                res = b/a;
            else
                res = 0;

            auto *res_node = new Node;
            res_node->prev = cur_node;
            res_node->value = res;
            cur_node = res_node;
            // std::cout << res << std::endl;
        }
        std::cin >> val;
    }
    std::cout << cur_node->value << std::endl;
    return 0;
}
