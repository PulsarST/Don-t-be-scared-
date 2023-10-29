CC = gcc

TARGET = bin\main.exe

INCLUDE = -I lib\raylib\include
DLL = -L lib\raylib\lib -l raylib
ARGUMENTS = -Wall
ARGUMENTS += -Wextra
ARGUMENTS += -Wpedantic
ARGUMENTS += --std=c2x
ARGUMENTS += -03

SRC = $(shell find src -name "*.c")

all: compile run

compile:
	$(CC) $(ARGUMENTS) $(SRC) -o $(TARGET) $(INCLUDE) $(DLL)

run:
	$(TARGET)