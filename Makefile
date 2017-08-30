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

design_00: $(TARGET)
	bash -c "./$(TARGET) Benchmark/design_00.isc"
design_01: $(TARGET)
	bash -c "./$(TARGET) Benchmark/design_01.isc"
design_02: $(TARGET)
	bash -c "./$(TARGET) Benchmark/design_02.isc"
clean:
	$(RM) $(TARGET) *.o *.html
