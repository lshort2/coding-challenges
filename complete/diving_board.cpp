// Luke-Luke dynamic
// 16.11 from Cracking the Coding Interview
#include<iostream>
#include<vector>

std::vector<int> allDivingBoardLengths(int k, int longer, int shorter) {
  std::vector<int> vec;

  for(int i=0, j=k; i<=k; i++, j--) {
    vec.push_back(i*longer + j*shorter);
  }

  return vec;
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

