#include <iostream>
#include "monitor.h"

int main() {
    std::cout << "=== 系統效能監控工具 ===" << std::endl;

    readCPU();
    readMem();

    std::cout << "=== 監控結束 ===" << std::endl;
    return 0;
}
