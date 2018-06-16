//Luke Short
// 16.21 from Cracking the Coding Interview
#include<iostream>
#include<algorithm>
#include<vector>
using std::vector;


std::pair<int, int> sumSwap(vector<int> a, vector<int> b) {
  // Given
  int sumA = 0;
  for(auto it: a) {
    sumA += it;
  }
  std::cout<< "sumA: " <<sumA <<std::endl;

  int sumB = 0;
  for(auto it: b) {
    sumB += it;
  }
  std::cout<< "sumB: " <<sumB <<std::endl;

  int newDiff = std::abs(sumA - sumB)/2;
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  // 1.) a smaller first
  unsigned int i=0;
  unsigned int j=0;
  for(; i<a.size(); i++) {
    while(b[j] - a[i] < newDiff && j<b.size()) {
      j++;
    }

    if(b[j] - a[i] == newDiff) {
      return std::make_pair(b[j], a[i]);
    }
  }

  // 2.) b smaller first
  i=0;
  j=0;
  for(; i<a.size(); i++) {
    while(a[i] - b[j] < newDiff && i<a.size()) {
      i++;
    }

    if(b[j] - a[i] == newDiff) {
      return std::make_pair(b[j], a[i]);
    }
  }


  return std::make_pair(7,7);
}

// Given two arrays of integers, find a pair of values 
// (one value from each array) that you can swap to give 
// the two arrays the same sum.
int main() {
  vector<int> a = {4, 1,2, 1, 1, 2};
  vector<int> b = {3, 6, 3, 3};  
  std::pair<int, int> res = sumSwap(a, b);

  std::cout<< "res.first: " <<res.first <<std::endl;
  std::cout<< "res.second: " <<res.second <<std::endl;

  return 0;
}

