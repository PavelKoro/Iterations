CC = g++
CFLAGS = -Wall -Wextra

all: build

build: Matrix2D.cpp vector.cpp iterat.cpp main.cpp
	$(CC) $(CFLAGS) Matrix2D.cpp vector.cpp iterat.cpp main.cpp -o main