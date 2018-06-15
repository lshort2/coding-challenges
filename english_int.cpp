// Luke-Luke dynamic
// 16.8 from Cracking the Coding Interview
#include<iostream>
#include<string>
#include<cmath>

// convert a single digit from an int to a string
// i.e. 9 --> "nine"
std::string digitToString(int d) {
  switch(d) {
    case 9:
      return "nine";
    case 8:
      return "eight";
    case 7:
      return "seven";
    case 6:
      return "six";
    case 5:
      return "five";
    case 4:
      return "four";
    case 3:
      return "three";
    case 2:
      return "two";
    case 1:
      return "one";
    default:
      return "";
  }
}

// used for converting tens digits for numbers greater than 19
// i.e. 4 --> "forty"
std::string tensToString(int d) {
  switch(d) {
    case 9:
      return "ninety";
    case 8:
      return "eighty";
    case 7:
      return "seventy";
    case 6:
      return "sixty";
    case 5:
      return "fifty";
    case 4:
      return "forty";
    case 3:
      return "thirty";
    case 2:
      return "twenty";
    default:
      return "";
  }
}

// convert numbers 10 to 19 in "English"
// i.e. 12 --> "twelve"
std::string teensToString(int teens) {
  switch(teens) {
    case 19:
      return "nineteen";
    case 18:
      return "eighteen";
    case 17:
      return "seventeen";
    case 16:
      return "sixteen";
    case 15:
      return "fifteen";
    case 14:
      return "fourteen";
    case 13:
      return "thirteen";
    case 12:
      return "twelve";
    case 11:
      return "eleven";
    default:
      return "ten";
  }
}

// convert integer to string in "English"
// i.e. 1337 --> "one thousand three hundred thirty seven"
std::string englishInt(int changeMe) {
  bool isNeg = false;

  // check if number is zero or negative
  if(changeMe == 0) {
    return "zero";
  }
  else if(changeMe < 0) {
    isNeg = true;
    changeMe = std::abs(changeMe);
  }

  // hold strings for various digit "places" in string array
  const std::string places[] = {
    "none",
    "thousand",
    "million",
    "billion",
    "trillion"
  };


  std::string ret = "";

  for(int invar=1, i=0; changeMe/invar; invar*=1000, i++) {
    int temp = changeMe / invar;
    temp %= 1000;
    std::string tempString = "";

    // evalue tens and ones digit
    if(temp%100 < 20 && temp%100 > 9) {
      tempString = teensToString(temp%100);
    }
    else {
      int ones = temp%10;
      tempString = digitToString(ones);

      int tens = temp % 100 / 10;
      if(tens) {
        if(tempString.empty()) {
          tempString = tensToString(tens);
        }
        else {
          tempString = tensToString(tens) + " " + tempString;
        }
      }
    }

    // evaluate hundreds digit
    if(temp > 99) {
      int hundreds = temp % 1000 / 100;

      if(tempString.empty()) {
        tempString = digitToString(hundreds) + " hundred";
      }
      else {
        tempString = digitToString(hundreds) + " hundred " + tempString;
      }
    }

    if(i > 0 && !tempString.empty()) {
      tempString += " " + places[i];
    }

    if(ret.empty()) {
      ret = tempString;
    }
    else{
      ret = tempString + " " + ret;
    }
  }

  if(isNeg) {
    return "negative " + ret;
  }
  else {
    return ret;
  }
}

int main() {
  std::cout<< 1337 <<" is: " <<englishInt(1337) <<std::endl;
  std::cout<< -1337 <<" is: " <<englishInt(-1337) <<std::endl;
  std::cout<< 4321 <<" is: " <<englishInt(4321) <<std::endl;
  std::cout<< 3412 <<" is: " <<englishInt(3412) <<std::endl;
  std::cout<< 4 <<" is: " <<englishInt(4) <<std::endl;
  std::cout<< 0 <<" is: " <<englishInt(0) <<std::endl;
  std::cout<< -1000000 <<" is: " <<englishInt(-1000000) <<std::endl;
  std::cout<< -10000000 <<" is: " <<englishInt(-10000000) <<std::endl;
  std::cout<< -100000000 <<" is: " <<englishInt(-100000000) <<std::endl;
  std::cout<< -111111111 <<" is: " <<englishInt(-111111111) <<std::endl;

  return 0;
}
