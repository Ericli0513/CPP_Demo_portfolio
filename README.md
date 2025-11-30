# C++ Demo portfolio

1.cpp-pipeline-demo project    
2.driver_test_project    
3.module_integration_project1
4.module_integration_project2
5.sys_monitor_project
6.tv_integration_project

--------------------------------------------------------------------------------------------------------
1. cpp-pipeline-demo project

[![C++ CI](https://github.com/Ericli0513/cpp-demo/cpp-pipeline-demo/actions/workflows/ci.yml/badge.svg)]
(https://github.com/Ericli0513/cpp-demo/cpp-pipeline-demo/actions)

## 📌 專案介紹
這是一個簡單的 C++ 專案範例，展示如何同時支援：
- **Linux CLI 編譯**（Makefile）
- **VS Code 開發**（tasks.json + launch.json）
- **Shell Script 一鍵操作**（編譯、執行、清理、測試）
- **GitHub Actions CI/CD**（自動化編譯與測試）

此專案結構清晰，適合展示工程師的完整開發流程。

## 📂 專案結構
cpp-pipeline-demo/ 
├── src/ # 主程式碼 
├── tests/ # 單元測試 
├── Makefile # 編譯規則 
├── run.sh # 一鍵編譯/執行/清理/測試
├── .vscode/
│   ├── tasks.json
│   └── launch.json 
└── .github/
    └── workflows/
        └── ci.yml   ← CI/CD 設定檔 (含 artifact 上傳)

## 開發環境
Ubuntu (WSL2 / Linux)
GCC / G++ 編譯器
Make / Shell Script
VS Code + Remote WSL 插件

## 🎯 專案定位
這個專案展示了完整的工程師流程：
本地開發：CLI +VS Code 提升開發效率
命令列編譯：Makefile + Shell Script 展現嵌入式/Linux 工程師風格，自動化腳本。
          一鍵自動化，支援「編譯、執行、清理、測試」。
自動化測試：單元測試確保程式正確性
CI/CD + Artifact：雲端自動編譯與測試，成果可下載驗證，符合工業級 DevOps 要求。

## 📈 未來擴充
增加更多單元測試
整合 cmake 支援跨平台編譯
加入 Dockerfile，提供容器化環境

## ☁️ 下載 CI/CD Artifact
每次 push 或 PR 到 main 分支，GitHub Actions 會自動：
編譯專案並執行測試
產生 binary (demo)
上傳到 Artifacts 區域

下載方式
前往 GitHub 專案頁面 → Actions → 點選最新的 workflow run
在頁面底部找到 Artifacts 區塊
下載 demo-binary.zip
解壓縮後即可執行： ./demo

--------------------------------------------------------------------------------------------------------
2.driver_test_project

「開發 Driver 測試工具 (C++/Linux)，使用裝置檔案存取與自動化測試案例，驗證 Driver 初始化、效能與穩定性。」
「我設計了 Driver 測試工具，並用 Shell Script 包裝成自動化流程，只要一個指令就能完成編譯、執行、清理，
方便團隊快速驗證 Driver。」

--------------------------------------------------------------------------------------------------------
3.module_integration_project1
「設計 Linux 模組整合與自動化載入工具 (C++/Shell)，支援模組載入、測試與卸載流程，並產生 log，提升系統整合效率。」
「我在 Demo 裡用 /dev/null 或系統工具模擬，但設計時已考慮真實 Driver 測試流程 (insmod/rmmod + log 收集)。」

--------------------------------------------------------------------------------------------------------
4.module_integration_project2
「設計 Linux 模組整合工具 (C++/Shell)，結合物件導向模組管理與自動化載入/卸載流程，並產生 log，提升系統整合效率。」
這樣的「結合版」程式：
OOP 結構：用 Module 類別管理模組狀態。
Linux 整合：在 load/unload 裡呼叫 system()，模擬 insmod/rmmod，並寫 log。
Shell Script：一鍵完成編譯、執行、清理。

--------------------------------------------------------------------------------------------------------
5.sys_monitor_project
「開發系統效能監控工具 (C++/Linux)，讀取 /proc 系統檔案監控 CPU 與記憶體使用率，並透過 Shell Script 
自動化流程產生 log。」

--------------------------------------------------------------------------------------------------------
6.tv_integration_project
「開發 TV 系統整合測試工具 (C++/Linux)，結合 Shell Script 自動化流程，透過 cec-client、amixer、ping 
驗證 HDMI/CEC、音訊切換與網路連線，並產生測試 log。」

---
## 🧪 License | 授權條款

This project is for **personal IoT learning and portfolio purposes only**.  
本專案為個人學習與作品展示用途，未授權第三方轉載、教學、商業或競賽使用。

**License:**CC BY-NC-ND 4.0** 
Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International  
創用 CC「姓名標示－非商業性－禁止改作 4.0 國際」授權條款  

✅ 可瀏覽與參考技術流程  
❌ 不得轉載整段程式碼進行授課或出版  
❌ 不得修改為二創內容再發佈  
❌ 不得用於商業或競賽活動



