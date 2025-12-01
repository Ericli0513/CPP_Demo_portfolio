#!/bin/bash
# 自動化流程：編譯 → 測試 → 清理

echo "===== 開始 Linux 模組整合測試流程 ====="

# Step 1: 編譯
echo "[INFO] 編譯專案..."
make
if [ $? -ne 0 ]; then
    echo "[ERROR] 編譯失敗，停止流程"
    exit 1
fi

# Step 2: 測試模組載入/卸載
echo "[INFO] 測試模組載入/卸載..."
./module_tool load video
./module_tool load audio
./module_tool unload video
./module_tool unload audio
./module_tool load network
./module_tool unload network

# Step 3: 清理檔案
echo "[INFO] 清理編譯檔案..."
make clean

echo "===== Linux 模組整合測試流程完成，Log 已保存到 module.log ====="
