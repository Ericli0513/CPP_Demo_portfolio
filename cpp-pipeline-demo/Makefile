CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = src/main.cpp src/utils.cpp
TARGET = demo
TEST_SRC = tests/test_utils.cpp src/utils.cpp
TEST_TARGET = test_demo

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
