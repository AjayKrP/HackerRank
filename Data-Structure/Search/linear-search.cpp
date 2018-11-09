
#include <iostream>
#include <array>

auto main() -> int {
    std::array<int, 6> arr = {5, 4, 3, 8, 9, 3};
    int key = 9;
    bool found = false;
    for (auto x: arr) {
        if (x == key) {
            found = true;
            break;
        }
    }
    if (found) {
        std::cout << "Found!!!\n";
    } else {
        std::cout << "Not Found!!!\n";
    }
}
