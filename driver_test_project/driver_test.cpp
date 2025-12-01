#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "driver_test.h"

// 使用 /dev/null 模擬 Driver 裝置
const char* DRIVER_PATH = "/dev/null";

// 初始化測試：檢查能否開啟裝置檔案
bool testInitialization() {
    std::cout << "[INFO] 驗證 Driver 初始化..." << std::endl;
    std::ofstream dev(DRIVER_PATH);
    if (!dev.is_open()) {
        std::cerr << "[ERROR] 無法開啟裝置檔案: " << DRIVER_PATH << std::endl;
        return false;
    }
    dev << "init test" << std::endl;
    dev.close();
    return true;
}

// 效能測試：大量寫入裝置檔案
bool testPerformance() {
    std::cout << "[INFO] 驗證 Driver 效能..." << std::endl;
    std::ofstream dev(DRIVER_PATH);
    if (!dev.is_open()) return false;

    for (int i = 0; i < 10000; i++) {
        dev << "performance test line " << i << "\n";
    }
    dev.close();
    return true;
}

// 穩定性測試：多次開啟/關閉裝置檔案
bool testStability() {
    std::cout << "[INFO] 驗證 Driver 穩定性..." << std::endl;
    for (int i = 0; i < 5; i++) {
        std::ofstream dev(DRIVER_PATH);
        if (!dev.is_open()) return false;
        dev << "stability cycle " << i+1 << "\n";
        dev.close();
        std::cout << "  Cycle " << i+1 << ": OK" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return true;
}
