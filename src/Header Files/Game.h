#pragma once

#include "Board.h"
#include "Person.h"
#include "Helpers.h"
#include <vector>

class Game {
  private:
    bool running;
    Board board;

    Person* playerList;

    Person* previousWinner;

    void screenClear();
    void dispIntro();
    void dispMenu();
    void dispScoreboard();
    void dispFinalScore();
    int getMenuChoice();
    void createPlayers();
    PlayerChoices getPlayerChoices(Person& player, bool badChoice = false);
    void displayBoard();
    bool checkWin();
    void dispOutro();
    void gameOver();

    void changeRole();
  public:
    Game();
    void setRunning(bool value);
    void run();
    bool isRunning();
    ~Game();
};