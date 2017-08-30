CC = gcc
CXX = g++
CXXFLAGS = -g --std=c++11 -w
VPATH = src/
TARGET = hw1
CASE ?= design_00.isc

.PHONY: clean all design_00 design_01 design_02

all: $(TARGET)

$(TARGET): main.cpp ScalableVectorGraphicsGenerator.o
	$(CXX) $(CXXFLAGS) $^ -o $@

ScalableVectorGraphicsGenerator.o: ScalableVectorGraphicsGenerator.hpp ScalableVectorGraphicsGenerator.cpp

test: $(TARGET)
		./$(TARGET) Benchmark/$(CASE)

clean:
	$(RM) $(TARGET) *.o *.html
