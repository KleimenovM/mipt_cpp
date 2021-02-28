#include <iostream>

struct Node {
    Node *next;
    int elem;
};

int main() {
    int n = 0;
    std::cin >> n;
    Node *list = nullptr; // задаём фиксированный указатель на первую ноду
    Node *cur_node = nullptr; // задаём указатель на текущую ноду

    for (int i = 0; i < n; i++) {
        int new_elem = 0;
        std::cin >> new_elem;

        Node *new_node = new Node; // соответстствует только что созданной ноде
        new_node->next = nullptr; // по умолчанию следующего элемента не существует
        new_node->elem = new_elem; // задаём значение элемента списка

        if (list == nullptr) // если в list ничего нет, то мы получили первый элемент
            list = new_node; // задаём list-у значение new_mode;
        else
            cur_node->next = new_node;

        cur_node = new_node; // следующая итерация цикла: объявляем следующую ноду текущей
    }

    int sum = 0;
    int count = 0;
    cur_node = list;
    while (cur_node != nullptr) {
        sum += cur_node->elem;
        count++;

        cur_node = cur_node->next;
    }

    int mean = (int) sum / (int) count;

    std::cout << mean << std::endl;

    cur_node = list;
    Node *next_node;

    while (cur_node != nullptr) {
        next_node = cur_node->next;
        delete cur_node;
        cur_node = next_node;
    }

    return 0;
}
