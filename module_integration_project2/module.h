#pragma once
#include <string>

class Module {
public:
    std::string name;
    bool loaded;

    // 預設建構子
    Module();

    // 帶參數建構子（使用 const std::string&，避免不必要複製）
    Module(const std::string& n);

    void load();
    void unload();
};
