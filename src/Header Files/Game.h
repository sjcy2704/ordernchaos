#pragma once

#include "Board.h"
#include "Person.h"
#include "Helpers.h"

class Game {
  private:
    bool running;
    Board board;

    Person* playerList;

    void screenClear();
    void dispIntro();
    void dispMenu();
    int getMenuChoice();
    void createPlayers();
    PlayerChoices getPlayerChoices(Person& player, bool badChoice = false);
    void displayBoard();
    void gameOver();
  public:
    Game();
    void setRunning(bool value);
    void run();
    bool isRunning();
    ~Game();
};