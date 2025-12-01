#include <iostream>
#include "module_test.h"

int main() {
    std::cout << "=== Linux 模組整合測試工具 ===" << std::endl;

    if (loadModule()) {
        std::cout << "[PASS] 模組載入成功" << std::endl;
    } else {
        std::cout << "[FAIL] 模組載入失敗" << std::endl;
    }

    if (testModule()) {
        std::cout << "[PASS] 模組測試成功" << std::endl;
    } else {
        std::cout << "[FAIL] 模組測試失敗" << std::endl;
    }

    if (unloadModule()) {
        std::cout << "[PASS] 模組卸載成功" << std::endl;
    } else {
        std::cout << "[FAIL] 模組卸載失敗" << std::endl;
    }

    std::cout << "=== 測試結束 ===" << std::endl;
    return 0;
}
