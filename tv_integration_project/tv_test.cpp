#include <iostream>
#include <cstdlib>
#include "tv_test.h"

// HDMI/CEC 測試：呼叫 cec-client 列出裝置
bool testHDMI() {
    std::cout << "[INFO] 驗證 HDMI/CEC 功能..." << std::endl;
    int ret = system("cec-client -l > hdmi_log.txt 2>&1");
    return (ret == 0);
}

// Audio 測試：呼叫 amixer 調整音量
bool testAudio() {
    std::cout << "[INFO] 驗證 Audio 功能..." << std::endl;
    int ret = system("amixer sset Master 50% > audio_log.txt 2>&1");
    return (ret == 0);
}

// Network 測試：ping Google DNS
bool testNetwork() {
    std::cout << "[INFO] 驗證 Network 連線..." << std::endl;
    int ret = system("ping -c 3 8.8.8.8 > net_log.txt 2>&1");
    return (ret == 0);
}
