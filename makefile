C=gcc
CXX=g++
CPPFLAGS = -g -Wall -std=c++11
TARGET = main

SRCS=main.cpp matrixclass.cpp

all: Macierze

Macierze: main.o matrixclass.o
	$(CXX) main.o matrixclass.o -o Macierze
main.o: main.cpp matrixclass.h

matrixclass.o: main.cpp matrixclass.h

clean:
	rm main.o matrixclass.o
