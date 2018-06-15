// Luke-Luke dynamic
#include<iostream>
#include<string>
#include<cmath>

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

std::string englishInt(int changeMe) {
  bool isNeg = false;
  if(changeMe == 0) {
    return "zero";
  }
  else if(changeMe < 0) {
    isNeg = true;
    changeMe = std::abs(changeMe);
  }
  std::string ret = "";
  const std::string places[] = {
    "none",
    "thousand",
    "million",
    "billion",
    "trillion"
  };


  for(int invar=1, i=0; changeMe/invar; invar*=1000, i++) {
    int temp = changeMe / invar;
    temp %= 1000;
    std::string tempString = "";

    // evalue tens and ones digit
    if(temp%100 < 20 && temp%100 > 9) {
      //handle teens and such
      tempString = teensToString(temp%100);
    }
    else {
      // evaluate ones digit
      int ones = temp%10;
      tempString = digitToString(ones);

      // evaluate tens digit
      int tens = temp%100;
      tens /= 10;
      if(tens > 0) {
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
      int hundreds = temp%1000;
      hundreds /= 100;

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
    ret = "negative " + ret;
  }
  return ret;
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
