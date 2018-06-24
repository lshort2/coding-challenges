#include"minesweeper.h"
#include<iostream>
#include<random>

enum spaces { blank=420, bomb=1337 };

//ctor
MineSweeper::MineSweeper(const int width, const int height):
  m_width(width), m_height(height) {

  // 1.) Create 2d vector for bombs
  std::vector<int> blankRow = std::vector<int> (m_width, blank);
  for(int iterY=0; iterY<m_height; iterY++) {
    m_grid.push_back(blankRow);
  }

  // 2.) Save additional blank 2d vector for actual display
  m_displayGrid = m_grid;
}

void MineSweeper::runApp() {
  int xCoord = -1;
  int yCoord = -1;
  getCoordinates(xCoord, yCoord);
  initializeGraph(xCoord, yCoord);
  drawGrid();

  while(!m_gameOver && m_numSpacesClicked < m_width*m_height - m_numBombs) {
    xCoord = -1;
    yCoord = -1;
    getCoordinates(xCoord, yCoord);
    clickSpace(xCoord, yCoord);
    drawGrid();
  }

  printScore();
}

void MineSweeper::printScore() {
  int numClickableSpaces = m_width * m_height - m_numBombs;
  std::cout<< "Total Score: " <<m_numSpacesClicked;
  std::cout<<"/" << numClickableSpaces <<std::endl;
}


/**
 * @brief Place bombs over entire logical grid except for the coordinates
 *   specified by x and y (first clicked space)
 *
 * @param x - x coordinate of first clicked space
 * @param y - y coordinate of first clicked space
 */
void MineSweeper::placeBombs(int x, int y) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<> dist(1, 100);

  for(int iterY=0; iterY<m_height; iterY++) {
    for(int iterX=0; iterX<m_width; iterX++) {
      int rint = dist(mt);
      if(rint <= 15 && !(iterX == x && iterY == y)) {
        m_grid[iterY][iterX] = bomb;
        m_numBombs++;
      }
    }
  }
}

void MineSweeper::initializeGraph(int x, int y) {
  placeBombs(x, y);
  clickSpace(x, y);
}

void MineSweeper::clickSpace(int x, int y) {
  if(isBomb(x, y)) {
    std::cout<< "fatality.......\n";
    m_gameOver = true;
  }
  else {
    m_displayGrid[y][x] = numSurroundingBombs(x, y);
    ++m_numSpacesClicked;

    if(numSurroundingBombs(x, y) == 0) {
      for(int iterY=y-1; iterY<y+2; iterY++) {
        for(int iterX=x-1; iterX<x+2; iterX++) {
          if(inRange(iterX, iterY) && m_displayGrid[iterY][iterX] == blank) {
            clickSpace(iterX, iterY);
          }
        }
      }
    }
  }
}

void MineSweeper::revealRecurSpace(int x, int y) {
  std::cout<< "reveal (" <<x <<", " <<y <<") in m_displayGraph\n";
  std::cout<< "and recur...\n";
}

void MineSweeper::getCoordinates(int& x, int& y) {
  bool firstTime = true;
  x = -1;
  y = -1;

  while(!inRange(x, y)) {
    if(!firstTime) {
      std::cout<< "Invalid coordinates, please try again\n";
    }

    std::cout<< "Enter x coodinate\n";
    std::cin>> x;
    std::cout<< "Enter y coodinate\n";
    std::cin>> y;

    firstTime = false;
  }
}

bool MineSweeper::inRange(int x, int y) {
  return x >= 0 && x < m_width && y >= 0 && y < m_height;
}

bool MineSweeper::isBomb(int x, int y) {
  return m_grid[y][x] == bomb;
}

int MineSweeper::numSurroundingBombs(int x, int y) {
  int bombCount = 0;

  for(int iterY=y-1; iterY<y+2; iterY++) {
    for(int iterX=x-1; iterX<x+2; iterX++) {
      if(inRange(iterX, iterY) && isBomb(iterX, iterY) 
        && !(iterY == y && iterX == x)) {
        bombCount++;
      }
    }
  }
  return bombCount;
}

void MineSweeper::drawGrid() {
  std::cout<< "/" <<std::string(m_width, '-') <<"\\\n";
  for(int iterY=0; iterY<m_height; iterY++) {
    std::cout<< "|";
    for(int iterX=0; iterX<m_width; iterX++) {
      if(m_gameOver) {
        if(isBomb(iterX, iterY)) {
          std::cout<< 'B';
        }
        else {
          std::cout<< '-';
        }
      }
      else {
        if(m_displayGrid[iterY][iterX] == blank) {
          std::cout<< '-';
        }
        else {
          std::cout<< m_displayGrid[iterY][iterX];
        }
      }
    }
    std::cout<< "|\n";
  }
  std::cout<< "\\" <<std::string(m_width, '-') <<"/\n";
}

