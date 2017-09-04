CC = gcc
CXX = g++
CXXFLAGS = -g --std=c++11 -w
VPATH = src/
TARGET = hw1
CASE ?= design_00.isc

.PHONY: clean all test

all: $(TARGET)

$(TARGET): main.cpp ScalableVectorGraphicsGenerator.o Network.o  Gate.o
	$(CXX) $(CXXFLAGS) $^ -o $@

ScalableVectorGraphicsGenerator.o: ScalableVectorGraphicsGenerator.hpp ScalableVectorGraphicsGenerator.cpp

Network.o: Network.hpp Network.cpp

Gate.o: Gate.hpp Gate.cpp

test: $(TARGET)
		./$(TARGET) Benchmark/$(CASE)

clean:
	$(RM) $(TARGET) *.o *.html
