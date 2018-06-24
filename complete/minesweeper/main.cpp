//Luke Short
#include<iostream>
#include"minesweeper.h"

int main() {
  MineSweeper game(16, 16);
  std::cout<< "Running 16x16 game.\n";
  game.runApp();

  return 0;
}

