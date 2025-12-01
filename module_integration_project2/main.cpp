#include <iostream>
#include <string>
#include <map>
#include "module.h"

using namespace std;

int main(int argc, char* argv[]) {
    map<string, Module> modules;
    modules["video"] = Module("video");
    modules["audio"] = Module("audio");
    modules["network"] = Module("network");

    if (argc < 3) {
        cout << "使用方式: ./module_tool [load/unload] [模組名稱]" << endl;
        return 1;
    }

    string action = argv[1];
    string target = argv[2];

    if (modules.find(target) == modules.end()) {
        cout << "模組不存在: " << target << endl;
        return 1;
    }

    if (action == "load") modules[target].load();
    else if (action == "unload") modules[target].unload();
    else cout << "未知操作: " << action << endl;

    return 0;
}
