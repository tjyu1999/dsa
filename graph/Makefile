# a makefile for building a test program to verify sort algorithm

CXX = g++
CFLAGS = -I../utils -Wall $(warnflags)
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -fno-diagnostics-show-option
LDFLAGS = 
LDLIBS =

TARGET = demo
SRCS = demo.cpp bfs.cpp dfs.cpp ../utils/utils.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CFLAGS) $(SRCS) $(LDLIBS) -o $(TARGET)

clean::
	rm -f $(TARGET)

.PHONY: clean
