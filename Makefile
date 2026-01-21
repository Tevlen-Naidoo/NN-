CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++17

SRCS := $(shell find . -name "*.cpp")
OBJS := $(SRCS:.cpp=.o)

TARGET := main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)


