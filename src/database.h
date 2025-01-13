#ifndef AG_DATABASE
#define AG_DATABASE

#include "company.h"
#include "utility.h"
#include <vector>

class Database {
  
  private:
    Utility* utility;
    std::vector<Company*> companies;
    std::vector<const std::string*> platforms;
    const char delimiter = '|';
    const std::string companiesFilename = "applications.db"; // contains list of applications by company with their status
    const std::string platformsFilename = "platforms.db"; // contains list of used job boards / platforms
  
  public:
    Database(Utility* utility): utility(utility) {}
    ~Database();
    Company* lookup(std::string& companyName);
    std::vector<Company*> getCompanies();
    std::vector<const std::string*> getPlatforms();
    const std::string* getPlatform(const int index);
    void savePlatform(const std::string* platform);
    void saveProgress();
    void loadDb();
    void loadPlatforms();
    void saveCompany(std::string& name, const std::string* platform, const std::string& todaysDate);
    void deleteCompany(const Company* company);
    void savePlatforms();
};

#endif
