#include "module.h"
#include <iostream>
#include <fstream>

// 簡單的 log function
void writeLog(const std::string& message) {
    std::ofstream logFile("module.log", std::ios::app); // append 模式
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}

Module::Module() : name("undefined"), loaded(false) {}

Module::Module(const std::string& n) : name(n), loaded(false) {}

void Module::load() {
    if (!loaded) {
        loaded = true;
        std::string msg = "模組已載入: " + name;
        std::cout << msg << std::endl;
        writeLog(msg);
    } else {
        std::string msg = "模組已經在載入狀態: " + name;
        std::cout << msg << std::endl;
        writeLog(msg);
    }
}

void Module::unload() {
    if (loaded) {
        loaded = false;
        std::string msg = "模組已卸載: " + name;
        std::cout << msg << std::endl;
        writeLog(msg);
    } else {
        std::string msg = "模組已經在卸載狀態: " + name;
        std::cout << msg << std::endl;
        writeLog(msg);
    }
}
