//Luke Short
#include<iostream>

int main()
{
  // a.) 1001 0011
  int a = 147;
  // b.) 0001 0100
  int b = 20;


  // EZ way
  a = a + b; // a: 167
  b = a - b; // b: 147
  a = a - b; // a: 20





  // 1337 bitwise way
  // (slightly better because it works w/ more types than just int)

  // a.) 1000 0111
  a = a ^ b;
  // b.) 1001 0011
  b = a ^ b;
  // a.) 0001 0100
  a = a ^ b;


  return 0;
}

