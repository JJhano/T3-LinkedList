CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS =  main.cpp
EXEC1 = main

.PHONY: all clean

all: $(EXEC1)

# Compilación de main.cpp
$(EXEC1): main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXEC1)
