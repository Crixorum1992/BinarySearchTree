
# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Target
TARGET=Class

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

# Makefile syntax:
# target: dependencies
#(tab) system command(s)

all: $(TARGET)

$(TARGET): main.o Class.o
	$(CC) main.o Class.o -o $(TARGET)

main.o: main.cpp Class.h
	$(CC) $(CFLAGS) main.cpp

list.o: Class.cpp Class.h
	$(CC) $(CFLAGS) Class.cpp

clean:
	rm *.o *~ $(TARGET)

