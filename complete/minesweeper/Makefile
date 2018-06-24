CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

minesweeperapp: main.o minesweeper.o
	$(CXX) -o minesweeperapp main.o minesweeper.o

main.o: main.cpp minesweeper.h

minesweeper.o: minesweeper.cpp minesweeper.h

# comment
