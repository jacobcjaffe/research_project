CC = g++
CFLAGS = -Wall -g

main: main.o dfa.o
    $(CC) $(CFLAGS) -o main main.o

main.o: main.cpp dfa.h
    $(CC) $(CFLAGS) -c main.cpp