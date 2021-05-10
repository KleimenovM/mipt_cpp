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

int *find_maxes(int *array, int begin, int end, int num) {
    int init = num;
    int *maxes = new int [num];
    int size = end;
    int cur = 0;
    while(num > 0){
        int pivot;
        if (end == begin)
            pivot = array[begin];
        else
            pivot = array[std::rand() % (end - begin) + begin];
        Pair pair = partition(array, begin, end, pivot);
        if (pair.a <= size - end)
            begin = pair.a;

        if (end - pair.b <= num){
            for (int i = 0; i < size - pair.b; i++) {
                maxes[cur + i] = array[pair.b + i];
                num -= end - pair.b;
                end = pair.b;

                for (int j = 0; j < init; j++)
                    std::cout << maxes[j] << ' ';
                std::cout << std::endl;

            }
            cur += init - num;
        }
        if (size - pair.b > num){
            begin = pair.b;
        }
    }
    return maxes;
}

int main(){
    int num;
    std::cin >> num;
    int q;
    std::cin >> q;
    int *line = new int [q];

    for (int i = 0; i < q; i++)
        std::cin >> line[i];
    // gathered all the elements into a list

    int *maxes = find_maxes(line, 0, q, num);
    qsort(maxes, num);

    for (int i = num; i > 0; i--)
        std::cout << maxes[i - 1] << std::endl;

    return 0;
}