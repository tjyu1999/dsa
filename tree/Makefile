# a makefile for building a demo program to verify tree structure

CXX = g++
CFLAGS = -I../utils -Wall $(warnflags)
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -fno-diagnostics-show-option
LDFLAGS = 
LDLIBS =

TARGET = demo
SRCS = demo.cpp traversal.cpp ../utils/utils.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CFLAGS) $(SRCS) $(LDLIBS) -o $(TARGET)

clean::
	rm -f $(TARGET)

.PHONY: clean
