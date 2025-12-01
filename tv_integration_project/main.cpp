#include <iostream>
#include "tv_test.h"

int main() {
    std::cout << "=== TV 系統整合測試工具 ===" << std::endl;

    if (testHDMI()) {
        std::cout << "[PASS] HDMI/CEC 測試成功" << std::endl;
    } else {
        std::cout << "[FAIL] HDMI/CEC 測試失敗" << std::endl;
    }

    if (testAudio()) {
        std::cout << "[PASS] Audio 測試成功" << std::endl;
    } else {
        std::cout << "[FAIL] Audio 測試失敗" << std::endl;
    }

    if (testNetwork()) {
        std::cout << "[PASS] Network 測試成功" << std::endl;
    } else {
        std::cout << "[FAIL] Network 測試失敗" << std::endl;
    }

    std::cout << "=== 測試結束 ===" << std::endl;
    return 0;
}
