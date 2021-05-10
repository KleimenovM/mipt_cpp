#include <iostream>
#include <cstdlib>

struct Pair{
    int a;
    int b;
};

Pair partition(int* array, int begin, int end, int pivot){
    int left = begin;
    int right = end - 1;

    for (int i = begin; i < end; i++){
        if (array[i] < pivot) {
            int tmp = array[i];
            array[i] = array[left];
            array[left] = tmp;

            left++;
        }
    }

    for (int i = end - 1; i >= begin; i--){
        if (array[i] > pivot) {
            int tmp = array[i];
            array[i] = array[right];
            array[right] = tmp;

            right--;
        }
    }

    Pair pair;
    pair.a = left;
    pair.b = right;

    return pair;
}

void quick_sort(int* array, int begin, int end){
    if (begin >= end - 1)
        return;

    int pivot = array[std::rand() % (end - begin) + begin];
    Pair pair = partition(array, begin, end, pivot);

    quick_sort(array, begin, pair.a);
    quick_sort(array, pair.b, end);
}

void qsort(int *array, int length){
    quick_sort(array, 0, length);
}

int main(){
    int q;
    std::cin >> q;
    int *line = new int [q];

    for (int i = 0; i < q; i++)
        std::cin >> line[i];

    qsort(line, q);

    for (int i = 0; i < q; i++)
        std::cout << line[i] << ' ';

    std::cout << std::endl;
    return 0;
}
