#include "utility.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

std::string Utility::prompt(std::string message) {
  std::cout<<message;
  std::string input;
  std::getline(std::cin, input);
  return input;
}

std::string Utility::createTodaysDate() {
  std::time_t time = std::time(nullptr);
  struct tm lt = *std::localtime(&time);
  std::ostringstream oss;
  oss << std::put_time(&lt, "%d/%m/%Y %H:%M:%S");
  return oss.str();
}

std::string* Utility::toLowercase(std::string& str) {
  std::string* copy = new std::string(str);
  std::transform(copy->begin(), copy->end(), copy->begin(), [](unsigned char c) { return std::tolower(c); });
  return copy;
}

bool Utility::containsLoosely(std::string& theString, std::string& theSubstring) {
  std::string* str1;
  std::string* str2;
  str1 = toLowercase(theString);
  str2 = toLowercase(theSubstring);
  bool res = ((*str1).find(*str2) != std::string::npos);
  delete str1;
  delete str2;
  return res;
}
