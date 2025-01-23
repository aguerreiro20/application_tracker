#ifndef AG_ENGINE
#define AG_ENGINE

#include "company.h"
#include "database.h"
#include "utility.h"
#include <vector>

class Engine {
  private: 
    Utility* utility;
    Database* database;
    void displayDb();
    const std::string* promptPlatform();
    void updateEntry(); 
    void deleteEntry();

  public:
    Engine();
    ~Engine();
    void init();
    void run();
    void lookupEntry(std::string& name);
    void saveProgress();

};

#endif // !AG_ENGINE

