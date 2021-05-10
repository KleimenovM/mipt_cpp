#include <iostream>

void sorted(int* array, int size){  // bubble sort
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (array[j] > array [j+1] ){
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1]=tmp;
            }
        }
    }
}

int main(){
    int length, value;
    std::cin >> length >> value;
    int *massive = new int [length];

    for (int i = 0; i < length; i++)
        std::cin >> massive[i];

    sorted(massive, length); // now massive is sorted

    bool is_true = false;

    for (int i = 0; i < length; i++){
        int val_i = massive[i];
        int left = i+1;
        int right = length - 1;
        int j = (left + right) / 2;
        while (left < right){
            if (val_i + massive[j] == value){
                is_true = true;
                break;
            }
            if (val_i + massive[j] > value)
                right = j;
            else
                left = j;

            j = (left + right) / 2;

            if (j == left || j == right)
                break;
        }
        if (val_i + massive[left] == value || val_i + massive[right] == value)
            is_true = true;
        if (is_true)
            break;
    }

    std::cout << is_true << std::endl;

    return 0;
}
