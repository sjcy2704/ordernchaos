#include <iostream>
#include "src/Header Files/Game.h"

int main() {
  if (!std::__fs::filesystem::exists("build/")) {
    system("mkdir build");
  }

  Game OrderNChaos;

  OrderNChaos.run();
}