#Name:Nicholas Reid
#Date:04/17/2017
#Program:Makefile
#Description: makes BinarySearchTree database with g++ compiler

CC=g++
TARGET=BinarySearchTree
CFLAGS=-c -Wall

all: $(TARGET)

# Creates Database useing target variable and nessecary output files
$(TARGET): main.o Class.o
	$(CC) main.o Class.o -o $(TARGET)

# Creates main and rational output files
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
rational.o: Class.cpp
	$(CC) $(CFLAGS) Class.cpp

# Cleans by removing output emac and target files	
clean:
	rm *.o *~ $(TARGET)