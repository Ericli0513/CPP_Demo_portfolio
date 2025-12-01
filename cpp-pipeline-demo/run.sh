#!/bin/bash

# 使用方式：
# ./run.sh        → 編譯並執行
# ./run.sh clean  → 清理編譯檔
# ./run.sh test   → 執行單元測試

if [ "$1" == "clean" ]; then
    echo "🧹 Cleaning build files..."
    make clean
    echo "✅ Clean done!"
    exit 0
fi

if [ "$1" == "test" ]; then
    echo "🧪 Running tests..."
    make test
    if [ $? -eq 0 ]; then
        echo "✅ All tests passed!"
    else
        echo "❌ Some tests failed!"
    fi
    exit 0
fi

# Step 1: 編譯
echo "🔨 Building project..."
make

# Step 2: 檢查是否成功編譯
if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
    echo "🚀 Running program..."
    ./demo
else
    echo "❌ Build failed!"
fi
