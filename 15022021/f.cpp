#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int* my_slightly_dumb_reallocation(int *source, unsigned int n_old, unsigned int n_new){
    if (n_new == 0) { // если запрошено 0 элементов, не надо выделять 0 байт памяти
        delete []source;
        return nullptr;
    }

    int *a = new int [n_new]; // создали память под новый массив длиной n_new

    if (source != nullptr) {
        for (int i = 0; i < n_new; i++) { // заполнили новый массив
            if (i == n_old)
                break;
            a[i] = source[i];
        }
    }

    delete []source;

    return a;
}

int main() {
    unsigned int n, i;
    cin >> n;
    int *a = my_slightly_dumb_reallocation(NULL, 0, n / 2); // тут у нас есть массив с мусором

    for (i = 0; i < n / 2; i++)
        cin >> a[i]; // здесь мы заполнили массив с мусором числами

    a = my_slightly_dumb_reallocation(a, n / 2, n);
    for (; i < n; i++)
        cin >> a[i];

    int sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    cout << sum << endl;

    a = my_slightly_dumb_reallocation(a, n, n / 2);
    a = my_slightly_dumb_reallocation(a, n / 2, 0);
    a = my_slightly_dumb_reallocation(a, 0, 0);
    return 0;
}
