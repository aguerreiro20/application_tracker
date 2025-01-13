
#include "engine.h"
#include <iostream>

int main(/*int argc, char** argv*/) {
  Engine* engine = new Engine();
  engine->run();
  delete engine;
  std::cout<<"Bye!\n";
  return EXIT_SUCCESS;
}

