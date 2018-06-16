// Luke-Luke dynamic
// 16.21 from Cracking the Coding Interview
#include<iostream>
#include<string>
#include<vector>
#include<array>

using namespace std;

void sum_swap(vector<int>, vector<int>, vector<int> &);

int main() {
  vector<int> test1{4, 1, 2, 1, 1, 2};
  vector<int> test2{3, 6, 3, 3};
  vector<int> result(2, -1);
  sum_swap(test1, test2, result);

  return 0;
}

void sum_swap(vector<int> a, vector<int> b, vector<int> &result) {
  int sum_a = 0;
  int sum_b = 0;
  for(int i = 0; i < a.size(); i++) {
    sum_a += a[i];
  }
  for(int i = 0; i < b.size(); i++) {
    sum_b += b[i];
  }

  for(int i = 0; i < a.size(); i++) {
    for(int i = 0; i < b.size(); i++) {
      if (sum_a - a[i] + b[i] == sum_b - b[i] + a[i]) {
        result[0] = a[i];
        result[1] = b[i];
        break;
      }
    }
  }

  cout << "before: " << sum_a << " " << sum_b << endl;
  cout << "after: " << sum_a - result[0] + result[1] << " " << sum_b - result[1] + result[0]  << endl;
  cout << "result: " << result[0] << " " << result[1] << endl;
}
