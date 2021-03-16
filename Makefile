# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o compress.o decompress.o
	$(CC) $(CFLAGS) -o main main.o compress.o decompress.o

# The main.o target can be written more simply

main.o: main.cpp compress.h decompress.h
	$(CC) $(CFLAGS) -c main.cpp

compress.o: compress.h

decompress.o: decompress.h