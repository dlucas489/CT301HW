CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Wfatal-errors -std=c++20

TARGET = GOLApp
SRCS = GOLApp.cpp GameOfLife.cpp parser.cpp errors.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

package: clean
	tar -cvf HW3_devin_lucas.tar $(SRCS) GameOfLife.h parser.h errors.h Makefile README.md
