#ifndef AG_COMPANY
#define AG_COMPANY

#include <ostream>
#include <string>

class Company {
  private: 
    std::string name;
    std::string platform;
    std::string status1;
    std::string date1;
    std::string status2;
    std::string date2;
    const char delimiter = '|';
  public:
    Company(std::string_view pName, const std::string pPlatform, std::string_view pStatus1, std::string_view pDate1, std::string_view pStatus2, std::string_view pDate2): 
      name{pName}, platform{pPlatform}, status1{pStatus1}, date1{pDate1}, status2{pStatus2}, date2{pDate2} {}
    std::string& getName() ;
    const std::string& getPlatform() const;
    const std::string printAsCsv() const;
    void updateStatus(std::string status, std::string date);

    friend std::ostream& operator<<(std::ostream& os, const Company* company);
    friend std::ostream& operator<<(std::ostream& os, const Company& company);
};
#endif
