// Luke-Luke dynamic
#include<iostream>
#include<string>

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

std::string englishInt(int changeMe) {
  std::string ret = "";

  const std::string places[] = {
    "none",
    "thousand",
    "million",
    "billion",
    "trillion"
  };


  for(int invar=1, i=0; invar <= changeMe*10; invar*=1000, i++) {
    int temp = changeMe / invar;
    temp %= 1000;
    std::string tempString = "";

    // evalue tens and ones digit
    if(temp%100 < 20 && temp%100 > 9) {
      //handle teens and such
      switch(changeMe%100) {
        case 19:
          tempString = "nineteen";
          break;
        case 18:
          tempString = "eighteen";
          break;
        case 17:
          tempString = "seventeen";
          break;
        case 16:
          tempString = "sixteen";
          break;
        case 15:
          tempString = "fifteen";
          break;
        case 14:
          tempString = "fourteen";
          break;
        case 13:
          tempString = "thirteen";
          break;
        case 12:
          tempString = "twelve";
          break;
        case 11:
          tempString = "eleven";
          break;
        default:
          tempString = "ten";
          break;
      }
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

    if(i > 0) {
      tempString += " " + places[i];
    }

    if(ret.empty()) {
      ret = tempString;
    }
    else{
      ret = tempString + " " + ret;
    }
  }

  return ret;
}

int main() {
  std::cout<< 1337 <<" is: " <<englishInt(1337) <<std::endl;
  std::cout<< 4321 <<" is: " <<englishInt(4321) <<std::endl;
  std::cout<< 3412 <<" is: " <<englishInt(3412) <<std::endl;

  return 0;
}
