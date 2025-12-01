#include <iostream>
#include "driver_test.h"

int main() {
    std::cout << "=== Driver Test Toolkit ===" << std::endl;

    if (testInitialization()) {
        std::cout << "[PASS] Driver 初始化測試成功" << std::endl;
    } else {
        std::cout << "[FAIL] Driver 初始化測試失敗" << std::endl;
    }

    if (testPerformance()) {
        std::cout << "[PASS] Driver 效能測試成功" << std::endl;
    } else {
        std::cout << "[FAIL] Driver 效能測試失敗" << std::endl;
    }

    if (testStability()) {
        std::cout << "[PASS] Driver 穩定性測試成功" << std::endl;
    } else {
        std::cout << "[FAIL] Driver 穩定性測試失敗" << std::endl;
    }

    std::cout << "=== 測試結束 ===" << std::endl;
    return 0;
}
