TARGET = ../graph.exe
FILE1 = data/adjacency_matrix.txt
FILE2 = data/graph.txt
FILE3 = data/coverage.txt
FILE4 = data/GraphViz.dot
FILE5 = data/GraphViz.dot.png

BROWSER     =   google-chrome
LCOVTEST    =   $(TARGET:.exe=.info)
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
	rm -f $(OBJECT) $(BIN)/$(TARGET) $(FILE1) $(FILE2) $(FILE3) $(FILE4) $(FILE5) 
