#include "database.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


Database::~Database() {
  for(const std::string* platform: platforms) {
    delete platform;
  }
  platforms.clear();
  for(const Company* company: companies) {
    delete company;
  }
  companies.clear();
}

std::vector<Company*> Database::getCompanies() {
  return companies;
}

std::vector<const std::string*> Database::getPlatforms() {
  return platforms;
}
const std::string* Database::getPlatform(const int index) {
  return platforms.at(static_cast<unsigned int>(index));
}
void Database::savePlatform(const std::string* platform) {
  platforms.push_back(platform);
  savePlatforms();
}

Company* Database::lookup(std::string& companyName) {
  std::cout<<"Looking up '"<<companyName<<"' ...\n";
  for(Company* company: companies) {
    if(utility->containsLoosely(company->getName(), companyName)) {
      return company;
    }
  }
  return nullptr;
}

void Database::saveProgress() {
  if (companies.empty()) {
    std::cout<<"Nothing to save!\n";
  } else {
    std::cout<<"Saving progress ...\n";
    std::ofstream ofs(companiesFilename);
    if (ofs.is_open()) {
      for(const Company* company: companies) {
        ofs << company->printAsCsv() << '\n';
      }
      ofs.close();
    }
  }
}

void Database::loadDb() {
  std::cout<<"Loading DB ... \n";
  std::ifstream ifs(companiesFilename);
  if (ifs.is_open()) {
    std::string name, platform, status1, date1, status2, date2, line;
    while(getline(ifs,  line)) {
      std::istringstream iss(line);
      std::getline(iss, name, delimiter);
      getline(iss, platform, delimiter); 
      getline(iss, status1, delimiter);
      getline(iss, date1, delimiter);
      getline(iss, status2, delimiter);
      getline(iss, date2);
      Company* company = new Company(name, platform, status1, date1, status2, date2);
      companies.push_back(company);
    }
    ifs.close();
  } else {
      std::cout<<"Save file not found. Creating a new one ...\n";
      std::ofstream ofs(companiesFilename);
      ofs.close();
      std::cout<<"Done!\n"; 
  }
}

void Database::loadPlatforms() {
  std::cout<<"Loading platforms ... \n";
  std::ifstream ifs(platformsFilename);
  if (ifs.is_open()) {
    std::string name;
    while(std::getline(ifs, name)) {
     platforms.push_back(new std::string(name));
    }
    ifs.close();
  }
}

void Database::saveCompany(std::string& name, const std::string* platform, const std::string& todaysDate) {
  companies.push_back(new Company(name, *platform, "Applied", todaysDate, "Awaiting response", "-"));
}

void Database::deleteCompany(const Company* company) {
      companies.erase(std::remove(companies.begin(), companies.end(), company), companies.end());
}

void Database::savePlatforms() {
  std::ofstream ofs(platformsFilename);
    if (ofs.is_open()) {
      for(const std::string* platform: platforms) {
        ofs << *platform << '\n';
      }
     ofs.close();
    }
}
