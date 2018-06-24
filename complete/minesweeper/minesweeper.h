#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include<vector>
using std::vector;

class MineSweeper {
   public:
       MineSweeper(const int width, const int height);
       void runApp();
   private:
       void clickSpace(int x, int y);
       void drawGrid();
       void getCoordinates(int& x, int& y);
       void initializeGraph(int x, int y);
       bool inRange(int x, int y);
       bool isBomb(int x, int y);
       int numSurroundingBombs(int x, int y);
       void placeBombs(int x, int y);
       void revealRecurSpace(int x, int y);

       vector<vector<int> > m_grid;
       vector<vector<int> > m_displayGrid;

       const int m_width;
       const int m_height;
       bool m_gameOver = false;
       int m_numBombs = 0;
       int m_numSpacesClicked = 0;
};

#endif
