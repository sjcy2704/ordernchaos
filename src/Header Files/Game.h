#pragma once

#include "Board.h"

class Game {
  private:
    bool running;
    Board board;
  public:
    Game();
    void setRunning(bool value);
    void run();
    void displayBoard();
    bool isRunning();
    ~Game();
};