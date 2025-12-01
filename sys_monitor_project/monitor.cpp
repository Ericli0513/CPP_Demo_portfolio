#include <iostream>
#include <fstream>
#include <string>
#include "monitor.h"

// 讀取 CPU 使用狀態
void readCPU() {
    std::ifstream file("/proc/stat");
    if (!file.is_open()) {
        std::cerr << "[ERROR] 無法讀取 /proc/stat" << std::endl;
        return;
    }

    std::string cpu;
    long user, nice, system, idle;
    file >> cpu >> user >> nice >> system >> idle;
    file.close();

    std::cout << "[INFO] CPU 狀態: user=" << user
              << " system=" << system
              << " idle=" << idle << std::endl;
}

// 讀取記憶體使用狀態
void readMem() {
    std::ifstream file("/proc/meminfo");
    if (!file.is_open()) {
        std::cerr << "[ERROR] 無法讀取 /proc/meminfo" << std::endl;
        return;
    }

    std::string key, unit;
    long value;
    while (file >> key >> value >> unit) {
        if (key == "MemTotal:") {
            std::cout << "[INFO] 總記憶體: " << value << " " << unit << std::endl;
        }
        if (key == "MemAvailable:") {
            std::cout << "[INFO] 可用記憶體: " << value << " " << unit << std::endl;
        }
    }
    file.close();
}
