
TARGET = ../graph.exe
FILE = data/matrix.txt

SRC = src
INC = include
BIN = bin

SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT=$(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))

CC = g++
CFLAGS = -std=c++17 -I$(INC)
$(BIN)/$(TARGET) : $(OBJECT)
		$(CC) -o $@ $^

$(BIN)/%.o : $(SRC)/%.cpp
		$(CC) $(CFLAGS) -c $< -o $@ 
clear :
	rm -f $(OBJECT) $(BIN)/$(TARGET) $(FILE)                                                                                            
