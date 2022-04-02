
TARGET = ../graph.exe
FILE = matrix.txt

SRC = src
INC = include
BIN = bin

SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT=$(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))

CC = g++
CFLAGS = -Wall -std=c++11 -I$(INC)
$(BIN)/$(TARGET) : $(OBJECT)
		$(CC) -o $@ $^

$(BIN)/%.o : $(SRC)/%.cpp
		$(CC) $(CFLAGS) -c $< -o $@ 
clear :
	rm -f $(OBJECT) $(BIN)/$(TARGET) $(FILE)                                                                                            
