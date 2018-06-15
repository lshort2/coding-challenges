// Luke-Luke dynamic
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

string int_to_english(int);
string get_number_string(int);


int main() {
  cout << 1 << " is: " << int_to_english(1) << endl;
  cout << 20 << " is: " << int_to_english(20) << endl;
  cout << 301 << " is: " << int_to_english(301) << endl;
  cout << 4321 << " is: " << int_to_english(4321) << endl;
  return 0;
}

string int_to_english(int input) {
  int temp_input = input;
  int length = 0;
  do {
    length++;
    temp_input /= 10;
  } while (temp_input);
  string output = "";
  temp_input = input;
  int j = pow(10,length-1); //1101 // j = 1100
  int k = 1;
  //cout << "\n FINAL: ";
  for(int i = length; i > 0; i--) {
    temp_input = input;
    //cout << temp_input / j << endl;
    temp_input /= j;
    temp_input = input % (j*10);
    //cout << temp_input << endl;
    temp_input /= j;
    //cout << temp_input << endl;
    temp_input *= j;
    //cout << "" << get_number_string(temp_input) << ' ';
    if (temp_input == 0) {
      // do nothing
    } else if (temp_input > 0 && temp_input < 10) {
      output += get_number_string(temp_input) + " ";
    } else if (temp_input > 9 && temp_input < 100) {
      output += get_number_string(temp_input) + " ";
    } else if (temp_input > 99 && temp_input < 1000) {
      output += get_number_string(temp_input/10);
      output += get_number_string(temp_input%10) + ' ';
    } else if (temp_input > 999 && temp_input < 1000) {
      output += get_number_string(temp_input/100);
      output += get_number_string(temp_input%100) + ' ';
    } else if (temp_input > 9999 && temp_input < 100000) {
      output += get_number_string(temp_input/1000);
      output += get_number_string(temp_input%1000) + ' ';
    } else {
      cout << "" << "FUCK"  << ' ';
    }



    //output += get_number_string(temp_input);
    j /= 10;
    k *= 10;
  }
  return output;
}


string get_number_string(int input) {


  switch(input) {
    case 0:
      return "zero";

    case 1:
      return "one";

    case 2:
      return "two";

    case 3:
      return "three";

    case 4:
      return "four";

    case 5:
      return "five";

    case 6:
      return "six";

    case 7:
      return "seven";

    case 8:
      return "eight";

    case 9:
      return "nine";

    case 10:
      return "ten";

    case 11:
      return "eleven";

    case 12:
      return "twelve";

    case 13:
      return "thirteen";

    case 14:
      return "fourteen";

    case 15:
      return "fifteen";

    case 16:
      return "sixteen";

    case 17:
      return "seventeen";

    case 18:
      return "eightteen";

    case 19:
      return "nineteen";

    case 20:
      return "twenty";

    case 30:
      return "thirty";

    case 40:
      return "fourty";

    case 50:
      return "fifty";

    case 60:
      return "sixty";

    case 70:
      return "seventy";

    case 80:
      return "eighty";

    case 90:
      return "ninety";

    case 100:
      return "hundred";

    case 1000:
      return "thousand";

    case 1000000:
      return "million";

    case 1000000000:
      return "billion";
    default:
      return "shit";
  }
}

/*
one
two
three
...
eleven
twelve
thirteen
..
twenty one
thirty two
thirty three
..
one hundred twenty five
two hundred two
..
five thousand three hundred fifty six
six thousand eight hundred two
..
seventeen thousand nine hundred four
eighteen thousand two hundred fifty five
..
one hundred thousand nine hundred two
two hundred fifty two thousand five hundred twenty two
..
one million eight hundred twenty five thousand seventy five
four million two hundred fifty two thousand seven hundred two
*/
