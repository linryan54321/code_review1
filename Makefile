# Makefile

# 編譯器
CXX = g++
# 編譯選項
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
# 執行檔名稱
TARGET = bst_bug

# 原始碼檔案
SRCS = bst_bug.cpp
# 物件檔（將 .cpp 換成 .o）
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
