
#include "engine.h"
#include "version.h"
#include <iostream>

int main(int argc, char** argv) {
  std::cout<<"Git commit hash: "<<GIT_COMMIT_HASH<<"\n";
  std::cout<<"Git commit message: "<<GIT_COMMIT_MESSAGE<<"\n";
  Engine* engine = new Engine();
  if (argc > 1) {
    std::string str = argv[1];
    engine->init();
    engine->lookupEntry(str);
    engine->saveProgress();
  } else {
    engine->run();
  }
  delete engine;
  std::cout<<"Bye!\n";
  return EXIT_SUCCESS;
}

