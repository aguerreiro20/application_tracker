#include "engine.h"
#include "database.h"
#include <iostream>
#include <pstl/glue_algorithm_defs.h>
#include <string>

Engine::Engine() {
  utility = new Utility();
  database = new Database(utility); 
}

Engine::~Engine() {
  std::cout<<"Cleaning up workspace ...\n";
  delete utility;
  delete database;
}

void Engine::displayDb() {
  std::cout<<"Displaying DB ...\n";
  int i = 1;
  for(const Company* company: database->getCompanies()) {
    std::cout<< i <<  ": "<< company <<"\n";
    i++;
  }
}

const std::string* Engine::promptPlatform() {
  const std::string* res;
  std::cout<<"Which platform did you use for this company ?\n";
  int i = 0;
  std::cout<<"0) Add a new one \n";
  for(const std::string* platform: database->getPlatforms()) {
    i++;
    std::cout<<i<<") "<< *platform<< "\n";
  }
  int selection = -1;
  int max = database->getPlatforms().size();
  bool invalidInput = true;
  while (invalidInput) {
    std::string message = "Enter a number between 0 and " + std::to_string(max) + "\n--> ";
    try {
    selection = std::stoi(utility->prompt(message));
    invalidInput = selection < 0 || selection > max;
    } catch (std::invalid_argument& e) {
      std::cout<<"Could not convert number to string, please try again (error message: '"<<e.what()<<"').\n";
    }
  }
  if (selection == 0) {
    std::string input = utility->prompt("Enter platform name: \n--> ");
    res = new std::string(input);
    database->savePlatform(res);
  } else {
    res = database->getPlatform(selection-1);
  }
  return res;
}


void Engine::updateEntry() {
  std::string input = utility->prompt("Enter company to update;\n--> ");
  Company* company = database->lookup(input);
  if(company==nullptr) {
    std::cout<<"Company not found, returning to main menu.\n";
  } else {
    std::cout<<"Company found: [" << company << "]\n";
    input = utility->prompt("Enter new status:\n--> ");
    company->updateStatus(input, utility->createTodaysDate());
  }
}

void Engine::deleteEntry() {
  std::string input;
  input = utility->prompt("Enter company to delete;\n--> "); 
  Company* company = database->lookup(input);
  if(company==nullptr) {
    std::cout<<"Company not found, returning to main menu.\n";
  } else {
    std::cout<<"Company found: [" << company << "]\n";
    input = utility->prompt("Are you sure to delete it ? (y/n)\n--> ");
    if (input == "y") {
      database->deleteCompany(company);
      std::cout<<"Done!\n";
    } else {
      std::cout<<"Returning to main menu.\n";
    }
  }
   
}

void Engine::run () {
  bool running = true;
  database->loadDb();
  database->loadPlatforms();
  std::string message = "Enter\n0) to quit\n1) to display all entries in the DB\n";
  message += "2) to update an entry\n3) to delete an entry\n";
  message += "or type in the name of the company to search for:\n--> ";
  while (running) {
    std::string action = utility->prompt(message);
    if(action=="0"){
      running = false;
      database->saveProgress();
    } else if(action=="1") {
      displayDb();
    } else if(action=="2") {
      updateEntry();
    } else if(action=="3") {
      deleteEntry();
    } else {
      const Company* company = database->lookup(action);
      if(company==nullptr) {
        std::string response = utility->prompt("Company not found, save it ? (y/n)\n");
        if(response == "y") {
          const std::string* platform = promptPlatform();
          std::cout<<"Saving '"<<action<<"' from platform '"<< *platform <<"' ...\n";
          database->saveCompany(action, platform, utility->createTodaysDate());
        }
      } else {
        std::cout<<"Company found ! Details: \n ==> "<<company<<"\n";
      }
    }
  }
}

