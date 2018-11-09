#include <iostream>
#include <array>
#include <algorithm>

auto main() -> int {
    std::array<int, 9> arr = {1, 99, 3, 4, 5, 6, 2, 9, 0};
    bool sorted = true;
    int count = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sorted = true;
        for (int j = 0; j < arr.size()-1 - i; ++j) {
            if (arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
                sorted = false;
            }
            count++;
        }
        if (sorted) {
            break;
        }
    }

    std::cout << "No. of execution:\t" << count << std::endl;

    //Best case complexity O(n)
    for (auto x: arr) {
        std::cout << x << "\t";
    }
}
