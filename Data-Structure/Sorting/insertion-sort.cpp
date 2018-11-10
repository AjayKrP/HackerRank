#include <iostream>
#include <array>
#include <algorithm>

template <size_t SIZE>
void insertionSort(std::array<int, SIZE> &arr){
    int key;
    for (int i = 1; i < arr.size(); ++i) {
        key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

auto main() -> int {
    std::array<int, 9> arr = {33, 1, 2, 3, 4, 5, 6, 7, 8};
    insertionSort(arr);
    
    for (auto x: arr) {
        std::cout << x << "\t";
    }
}
