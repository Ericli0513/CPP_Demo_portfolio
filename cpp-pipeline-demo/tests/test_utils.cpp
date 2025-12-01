#include <iostream>
#include "../src/utils.h"

int main() {
    int result = add(2, 3);
    if (result == 5) {
        std::cout << "✅ Test Passed: add(2,3) == 5" << std::endl;
        return 0;
    } else {
        std::cerr << "❌ Test Failed: add(2,3) != 5 (got " << result << ")" << std::endl;
        return 1;
    }
}
