int* my_slightly_dumb_reallocation(int *source, unsigned int n_old, unsigned int n_new){
    if (n_new == 0) { // если запрошено 0 элементов, не надо выделять 0 байт памяти
        delete []source;
        return nullptr;
    }

    int *a = new int [n_new]; // создали память под новый массив длиной n_new

    if (source != nullptr) {
        for (int i = 0; i < n_old; i++) { // заполнили новый массив
            if (i == n_old)
                break;
            a[i] = source[i];
        }
    }

    delete []source;

    return a;
}