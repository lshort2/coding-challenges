// Luke-Luke dynamic
// 16.11 from Cracking the Coding Interview
#include<iostream>
#include<vector>

std::vector<int> allDivingBoardLengths(int k, int longer, int shorter) {
  if(k == longer && longer == shorter) {
    std::cout<< "stop giving me errors\n";
  }
  return {1, 2, 3};
}

int main() {
  std::cout<< "allDivingBoardLengths(5, 1, 9): " <<std::endl;
  std::cout<<"[ ";
  for(auto it:allDivingBoardLengths(5, 1, 9)) {
    std::cout<< it <<" ";
  }
  std::cout<< "]" <<std::endl;

  std::cout<< "allDivingBoardLengths(1, 2, 3): " <<std::endl;
  std::cout<<"[ ";
  for(auto it:allDivingBoardLengths(1, 2, 3)) {
    std::cout<< it <<" ";
  }
  std::cout<< "]" <<std::endl;

  std::cout<< "allDivingBoardLengths(4, 5, 6): " <<std::endl;
  std::cout<<"[ ";
  for(auto it:allDivingBoardLengths(4, 5, 6)) {
    std::cout<< it <<" ";
  }
  std::cout<< "]" <<std::endl;

  return 0;
}

