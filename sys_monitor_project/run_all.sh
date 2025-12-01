#!/bin/bash
# 自動化流程：編譯 → 執行 → 清理

echo "===== 開始 系統效能監控流程 ====="

# Step 1: 編譯
echo "[INFO] 編譯專案..."
make
if [ $? -ne 0 ]; then
    echo "[ERROR] 編譯失敗，停止流程"
    exit 1
fi

# Step 2: 執行監控
echo "[INFO] 執行監控工具..."
./sys_monitor | tee sys_log.txt
if [ $? -ne 0 ]; then
    echo "[ERROR] 監控工具執行失敗"
    exit 1
fi

# Step 3: 清理檔案
echo "[INFO] 清理編譯檔案..."
make clean

echo "===== 系統效能監控流程完成，Log 已保存到 sys_log.txt ====="
