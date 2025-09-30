CXX := g++
CXXFLAGS := -std=c++23 -O0 -MMD -MP
CPPFLAGS := -I./include -I./defs -I./external

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

TARGET := loader.out
TEST_TARGET := test.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) main.o $(TARGET) $(TEST_TARGET)

re:
	make clean
	make

-include $(DEPS)