#include "company.h"

std::string& Company::getName() {
  return name;
}

const std::string& Company::getPlatform() const{
  return platform;
}

const std::string Company::printAsCsv() const {
  return name + delimiter + platform + delimiter + status1 + delimiter + date1 + delimiter + status2 + delimiter + date2 ;
}

void Company::updateStatus(std::string status, std::string date) {
  status2 = status;
  date2 = date;
}

std::ostream& operator<<(std::ostream& os, const Company* company) {
  return os << *company;
} 

std::ostream& operator<<(std::ostream& os, const Company& company) {
  return os << company.name <<  " (" << company.platform << ") - " << 
    company.status1 << " (" << company.date1 << ") - " << 
    company.status2 << " (" << company.date2 << ")"; 
}


