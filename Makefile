# Specifying Compilers 
CXX = g++

# Compilation Options
CXXFLAGS = -std=c++11 -Wall

# Target executable file name
TARGET = my_build_system.out

# source file
SRC = gs.cpp

# Rule: Generate executable file
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -f $(TARGET)