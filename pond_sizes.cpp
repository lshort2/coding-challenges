// Luke Short
// 16.9 Pond Sizes
#include<iostream>
#include<vector>
#include<unordered_map>
using std::vector;
using std::pair;

vector<int> computePondSizes(vector<vector<int> > grid) {
  //                coords: y,x   , island #
  std::unordered_map<pair<int,int>, int> hashy;
  unsigned int numIslands = 0;
  std::vector<int> islandSizes;


  for(unsigned int y=0; y<grid.size(); y++) {
    for(unsigned int x=0; x<grid[0].size(); x++) {
      grid[y][x] = -1; //mark as visited
    }
  }

  return {};
}

int main() {
  vector<vector<int> > grid = {
    {0, 0, 1, 0},
    {2, 1, 1, 0},
    {3, 2, 1, 0},
    {3, 2, 1, 1},
    {2, 2, 0, 1},
    {2, 2, 0, 1}
  };
  // vector<vector<int> > grid = {
  //   {0, 0, 1, 0},
  //   {2, 1, 1, 0},
  //   {0, 2, 1, 0},
  //   {0, 2, 0, 1},
  //   {2, 0, 0, 0},
  //   {2, 2, 0, 1}
  // };

  vector<int> pondSizes = computePondSizes(grid);

  return 0;
}

