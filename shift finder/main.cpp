#include "cstdio"
#include <iostream>
#include <string>

namespace ShiftFinder {
}
int main() {
    std::string CharList;
    std::cin >> CharList;
    for (int i = 0; i < 26; i++) {
        std::cout << (int) CharList[i] - 65 - i << ",";
    }
}