# Compiler
GPP = g++

# Compilation flags
GPPFlags = -Wall -Wextra -Werror -Wfatal-errors -std=c++20
Debug = -g

# source and output names
HWNUM = HW1

SRC = $(wildcard *.cpp)

HEADER = $(wildcard *.h)

OBJ = $(SRC:.cpp=.o)

TARNAME = devin_lucas

# Target Name
TARGET = GOLparser

# compile
$(OBJ): $(SRC) $(OBJ)
	$(GPP) $(GPPFlags) $(SRC) -o $(TARGET) 

# clean
clean:
	rm -f $(TARGET) $(OBJ)
	@echo "Removed all object files."

package:
	tar -c Makefile $(SRC) $(HEADER) -f $(HWNUM)_$(TARNAME).tar
