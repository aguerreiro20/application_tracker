#ifndef AG_UTILITY
#define AG_UTILITY

#include <string>

class Utility {
  public:
    std::string prompt(std::string message);
    std::string createTodaysDate();
    std::string* toLowercase(std::string& str);
    bool containsLoosely(std::string& theString, std::string& theSubstring);
};

#endif // !AG_UTILITY
