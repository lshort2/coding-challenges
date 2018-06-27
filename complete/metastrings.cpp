// Geeks4Geeks problem: https://practice.geeksforgeeks.org/problems/meta-strings/0
#include <iostream>
#include <vector>

bool areMetaStrings(std::string a, std::string b) {
  if(a.size() != b.size()) {
    return false;
  }

  std::vector<int> mismatchedIndexes;
  for(int i=0; i<a.size(); i++) {
    if(a[i] != b[i]) {
      mismatchedIndexes.push_back(i);
    }
  }

  if(mismatchedIndexes.size() == 2) {
    int indx0 = mismatchedIndexes[0];
    int indx1 = mismatchedIndexes[1];

    if(a[indx0] == b[indx1] && a[indx1] == b[indx0]) {
      return true;
    }
  }

  return false;
}

int main() {
  int numIterations;
  std::cin>> numIterations;

  for(int i=0; i<numIterations; i++) {
    std::string a;
    std::string b;
    std::cin>> a;
    std::cin>> b;
    if(areMetaStrings(a, b)) {
      std::cout<< 1 <<std::endl;
    }
    else  {
      std::cout<< 0 <<std::endl;
    }
  }
  return 0;
}

