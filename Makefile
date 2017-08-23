CC = gcc
CXX = g++
CXXFLAGS = -g --std=c++11 -w
VPATH = src/
TARGET = hw1

.PHONY: clean all design_00 design_01 design_02

all: $(TARGET)

$(TARGET): Source.cpp Gate.o Network.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Gate.o: Gate.h Gate.cpp

Network.o: Network.h Network.cpp

design_00: $(TARGET)
	bash -c "./$(TARGET) < Benchmark/design_00.isc"
design_01: $(TARGET)
	bash -c "./$(TARGET) < Benchmark/design_01.isc"
design_02: $(TARGET)
	bash -c "./$(TARGET) < Benchmark/design_02.isc"
clean: 
	$(RM) $(TARGET) *.o
