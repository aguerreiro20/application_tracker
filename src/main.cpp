
#include "engine.h"
#include <iostream>

int main(int argc, char** argv) {
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

