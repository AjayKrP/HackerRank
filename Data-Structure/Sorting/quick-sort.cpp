#include <iostream>
#include <array>
#include <algorithm>

template <size_t SIZE>
int partition (std::array<int, SIZE>&arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);

}

template <size_t SIZE>
void quickSort(std::array<int, SIZE>&arr, int left, int right) {
    if (right - left <= 0) {
        return;
    } else{
        int partitionPoint = partition(arr, left, right);
        quickSort(arr, left, partitionPoint-1);
        quickSort(arr, partitionPoint+1, right);
    }
}

auto main() -> int {
    std::array<int, 9> arr = {33, 1, 200, 3, 48, 5, 6, 7, 8};
    quickSort(arr, 0, arr.size()-1);

    for (auto x: arr) {
        std::cout << x << "\t";
    }
}
