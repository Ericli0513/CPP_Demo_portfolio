#include <iostream>
#include <fstream>
#include <cstdlib>
#include "module_test.h"

// 模擬模組載入 (用 echo 模擬 insmod)
bool loadModule() {
    std::cout << "[INFO] 模擬載入模組..." << std::endl;
    int ret = system("echo 'insmod 模組成功' > module_log.txt");
    return (ret == 0);
}

// 模擬模組測試 (寫入 /dev/null)
bool testModule() {
    std::cout << "[INFO] 模擬測試模組..." << std::endl;
    std::ofstream dev("/dev/null");
    if (!dev.is_open()) return false;
    dev << "test data" << std::endl;
    dev.close();
    return true;
}

// 模擬模組卸載 (用 echo 模擬 rmmod)
bool unloadModule() {
    std::cout << "[INFO] 模擬卸載模組..." << std::endl;
    int ret = system("echo 'rmmod 模組成功' >> module_log.txt");
    return (ret == 0);
}
