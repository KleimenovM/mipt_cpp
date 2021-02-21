#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int* now_get_me_some_bytes(unsigned int n) {
    int *a = new int [n];
    return a;
}

void now_free_some_bytes(int *p) {
    delete []p;
}

int main() {
    unsigned int n;
    cin >> n; // n - длина массива
    int *a = now_get_me_some_bytes(n); // a - указатель, *a - массив
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    if (s % 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    now_free_some_bytes(a);  // a - указатель; функция очищает значение указателя (массив из new int)
    return 0;
}
