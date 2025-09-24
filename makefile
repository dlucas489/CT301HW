CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Wfatal-errors -std=c++20

TARGET = GOLparser
SRCS = HW1.cpp parser.cpp errors.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

HW1.o: HW1.cpp parser.h errors.h
	$(CXX) $(CXXFLAGS) -c HW1.cpp

parser.o: parser.cpp parser.h errors.h
	$(CXX) $(CXXFLAGS) -c parser.cpp

errors.o: errors.cpp errors.h
	$(CXX) $(CXXFLAGS) -c errors.cpp

tests.o: tests.cpp parser.h
	$(CXX) $(CXXFLAGS) -c tests.cpp

clean:
	rm -f $(OBJS) $(TARGET)

package: clean
	tar -cvf HW1_devin_lucas.tar $(SRCS) parser.h errors.h Makefile
