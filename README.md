# C Demo portfolio

1.driver_test
2.System Driver Test

-----------------------------------------------------------------------------------------------------
1.
# 簡易 Driver 測試工具 (C 語言)
  Driver Test (C)
  
## 🎯專案目標|Project Overview
此專案展示我能用 C 語言撰寫 Linux 下的系統程式，模擬「驅動測試工具」的概念：初始化、執行測試、輸出 log。
專案結構簡單，容易在短時間完成。

This project demonstrates my ability to write Linux system programs in C, 
simulating the concept of a “driver test tool” with initialization, test execution, 
and log output. 
The project structure is simple and can be completed within a short timeframe.

## ✨ 專案特色 | Key Features
此專案使用 C 語言撰寫，展示 Linux 下的系統呼叫與 log 管理。
同時也能以 C++ 撰寫模組化版本，展現 C / C++ 的雙語言能力。

This project is implemented in C, demonstrating system calls and log management under Linux. 
It can also be written in C++ as a modular version, showcasing dual-language capability 
in C and C++.

-----------------------------------------------------------------------------------------------------
2.
# 系統驅動測試工具 (C) 
  System Driver Test (C)
  
## 🎯專案目標|Project Overview
此專案展示我在 **C 語言**下的系統程式設計能力，包含多進程、IPC、執行緒、訊號處理、設備檢查與回退機制。  
專案模擬「驅動測試工具」的場景，確保在不同 Linux 環境下能正確執行並產生 log。

This project demonstrates my **system-level C programming skills** in a Linux environment, 
including multi-process, IPC, threading, signal handling, device checking, and fallback mechanisms. 

---

## ✨ 專案特色 | Key Features
- **多進程與 IPC** | **Multi-process & IPC**  
  使用 `fork` 與 `pipe` 建立父子行程並交換指令。  
  Uses `fork` and `pipe` to create child processes and exchange commands.  

- **外部指令執行** | **External Command Execution**  
  子行程透過 `execlp` 執行系統指令 (如 `uname -a`)。（可替換為需要的工具），捕捉成功/失敗。
  Child process executes system commands (e.g., `uname -a`) via `execlp`.  

- **執行緒與同步** | **Multi-threading & Synchronization**  
  背景 logger 執行緒定期記錄心跳訊息。  
  Background logger thread records heartbeat messages.  

- **訊號處理** | **Signal Handling**  
  支援 `SIGINT` / `SIGTERM`，安全關閉並清理資源。  
  Supports `SIGINT` / `SIGTERM` for safe shutdown and resource cleanup.  

- **設備節點檢查** | **Device Node Checking**  
  檢查 `/dev/i2c-1` 等設備路徑，若不存在則重試並回退。  
  Validates device paths (e.g., `/dev/i2c-1`); retries if unavailable, then fallback.  

- **錯誤處理與回退機制** | **Error Handling & Fallback** 
  使用 open/write/close 進行低階 I/O，嚴格檢查 errno。 
  失敗時記錄 WARN/ERROR，並自動切換到模擬模式。  
  Perform low-level I/O using open/write/close, with strict checking of errno.
  Logs WARN/ERROR and switches to simulation mode when device is missing.  
  
---

## 📂 專案結構 | Project Structure
sys_driver_test/ 
├── Makefile 
├── main.c 
├── sys_test.c 
├── sys_test.h 
└── logs.txt (執行後產生 | generated after execution)

---

## ⚙️ 編譯與執行 | Build & Run
```
make
./sys_driver_test
cat logs.txt
```
---

📝 範例輸出 | Example Output

終端機 | Terminal:
=== System Driver Test (C) ===
Driver initialized.
Driver test executed.
Driver closed.

logs.txt:
[2025-11-28 23:36:47] [INFO] Device node found, proceeding with real test
[2025-11-28 23:36:47] [INFO] system init complete
[2025-11-28 23:36:47] [HEARTBEAT] logger alive
Linux DESKTOP-N3SJV8D 6.6.87.2-microsoft-standard-WSL2 #1 SMP PREEMPT_DYNAMIC Thu Jun  5 18:30:46 UTC 2025 x86_64 x86_64 x86_64 GNU/Linux
[2025-11-28 23:36:47] [INFO] parent waiting for child
[2025-11-28 23:36:48] [INFO] child exec success
[2025-11-28 23:36:48] [INFO] system shutdown
[2025-11-28 23:36:48] [INFO] logger exiting

---

🔹 流程解釋 | Process Explanation

- **Device 檢查**：程式在初始化時先檢查 device node，確認存在後進入「真實測試模式」。  
- **System Init**：完成 signal handler、log 檔案、logger thread 的初始化。  
- **Heartbeat**：logger thread 開始定期輸出心跳訊息，顯示系統持續運作。  
- **Fork/Exec 測試**：parent 透過 pipe 傳遞指令，child 成功執行 `uname -a` 並輸出系統資訊。  
- **Shutdown 流程**：parent 等待 child 完成後，觸發 shutdown，logger thread 在結束前輸出最後訊息。  

👉 此 log 展示了完整的系統流程，順序設計確保 **可讀性** 與 **完整性**，同時強調這是一個 
**user-space 系統程式專案**，而非韌體或 kernel driver。

Device Check: During initialization, the program first checks the device node. If it exists, 
the program enters “real test mode.”
System Init: Completes initialization of the signal handler, log file, and logger thread.
Heartbeat: The logger thread begins outputting heartbeat messages periodically, indicating 
that the system is running continuously.
Fork/Exec Test: The parent process sends a command through a pipe, and the child successfully 
executes uname -a to output system information.
Shutdown Process: The parent waits for the child to finish, then triggers shutdown. 
The logger thread outputs its final message before exiting.

👉 This log demonstrates the complete system workflow. 
The sequence is designed to ensure readability and integrity, while emphasizing that 
this is a user-space system programming project, not firmware or a kernel driver.

---

## 💡技能強調 | Skills Highlighted
C 語言 | C Programming：Linux 系統呼叫、IPC、執行緒、訊號處理、設備檢查
系統整合能力 | System Integration：真實設備與模擬模式切換，確保穩定性
工業環境思維 | Industrial Mindset：錯誤處理、回退機制、結構化 log

C Programming: Linux system calls, IPC, multithreading, signal handling, device checking
System Integration: Switching between real device and simulation mode to ensure stability
Industrial Mindset: Error handling, fallback mechanisms, structured logging

🔧 延伸應用 | Extensions
替換外部指令 (如 i2cdetect, lsusb) | Replace external command (i2cdetect, lsusb)
修改設備路徑 (如 /dev/i2c-1) | Modify device path (/dev/i2c-1)
擴充 log 系統，整合至 CIM/MES | Extend logging system for CIM/MES integration

---

## 📌 對應的工程師類型|Relevant Engineer Profiles
嵌入式 / 驅動工程師：熟悉 Linux 下的設備節點、驅動測試、系統呼叫。
系統軟體工程師：能處理 IPC、多進程、多執行緒，並設計 log 與錯誤處理。
工控 / CIM/MES 系統整合工程師：需要在工業環境下確保程式穩定性，能處理「設備不存在 → 回退模擬模式」這種情境。

Embedded / Driver Engineer: Familiar with Linux device nodes, driver testing, and system calls.
System Software Engineer: Experienced in IPC, multi‑process, multithreading, and designing 
logs with error handling.
Industrial Control / CIM/MES Integration Engineer: Ensures program stability in industrial 
environments, capable of handling scenarios such as “device not available → fallback to 
simulation mode”.

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








