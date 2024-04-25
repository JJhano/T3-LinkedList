CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = permutacion.cpp main.cpp
EXEC1 = permutacion
EXEC2 = main

.PHONY: all clean

all: $(EXEC1) $(EXEC2)

# Compilación de permutacion.cpp
$(EXEC1): permutacion.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilación de main.cpp
$(EXEC2): main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXEC1) $(EXEC2)
