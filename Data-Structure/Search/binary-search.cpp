#include <iostream>
#include <array>

template<std::size_t SIZE>
bool binarySearch(std::array<int, SIZE> arr, int key) {
    int left = 0;
    auto right = static_cast<int>(arr.size());
    while (right >= left) {
        int mid = (left + right)/2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] > key) {
            right = mid + 1;
        } else{
            left = mid + 1;
        }
    }
    return false;
}

auto main() -> int {
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    int key = 4;
    if (binarySearch(arr, key)) {
        std::cout << "Found!!!\n";
    } else {
        std::cout << "Not Found!!!\n";
    }
}
