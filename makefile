CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Wfatal-errors -std=c++20

TARGET = HW2.a
SRCS = GameOfLife.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

GameOfLife.o: GameOfLife.cpp GameOfLife.h
	$(CXX) $(CXXFLAGS) -c GameOfLife.cpp

clean:
	rm -f $(OBJS) $(TARGET)

package: clean
	tar -cvf HW2_devin_lucas.tar GameOfLife.cpp GameOfLife.h Makefile
