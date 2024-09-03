# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = match-fixture-generator

# Source files
SRC = src/main.cpp src/fixtures.cpp src/csv_reader.cpp

# Include directories
INCLUDE = -Iinclude

# Output directory
OUTPUT_DIR = output/

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) $(OUTPUT_DIR)*.csv

.PHONY: all clean