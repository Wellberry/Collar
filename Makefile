CC=g++
INCLUDE=./include
SOURCE=./src/main.cpp ./include/collar.cpp
OBJECTS=$(SOURCE:.cpp=.o)
OUT=collar

build:
	clear
	$(CC) -o $(OUT) $(SOURCE) -I $(INCLUDE)