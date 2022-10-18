#pragma once

#include "Board.h"
#include "Person.h"
#include "Helpers.h"
#include <vector>

class Game {
  private:
    bool running;
    bool autosave;
    int turns;

    Board board;

    Person* playerList;

    Person* previousWinner;

    /// @brief Clear the screen
    void screenClear();

    /// @brief Display the introduction of the main menu
    void dispIntro();

    /// @brief Display the menu
    void dispMenu();

    /// @brief Display the scoreboard during the game
    void dispScoreboard();

    /// @brief Display the final score after the game is over
    void dispFinalScore();

    /// @brief Get the choice made from the player in the main menu
    /// @return 1, 2, 3
    int getMenuChoice();

    /// @brief Create two players for the game
    void createPlayers();

    /// @brief Map the player choices into struct PlayerChoices { token, position }
    /// @param player The current player making the choice
    /// @param badChoice If player made a invalid move
    /// @return {token, position}
    PlayerChoices getPlayerChoices(Person& player, bool badChoice = false);

    /// @brief Display board in terminal
    void displayBoard();

    /// @brief Check win for either Order or Chaos
    /// @return true false
    bool checkWin();

    /// @brief Display the end of the game
    void dispOutro();

    /// @brief Display the final score and thanks
    void gameOver();

    /// @brief Swap roles between the players
    void changeRole();

    /// @brief Ask whether the players want to auto-save the game
    void askToSave();

    /// @brief Clear all save files
    void clearSave();

    /// @brief Get whether there is a game saved or not
    /// @return true false
    bool getSaveStatus();

    /// @brief Set if the game is saved
    /// @param value True to set the game as saved and false for the opposite
    void setSaveStatus(bool value);

    /// @brief Save the game into text files
    void save();

    /// @brief Load the game from the text files
    void load();
  public:
    Game();

    /// @brief Set the variable running to true or false
    /// @param value True False
    void setRunning(bool value);

    /// @brief Run the game
    void run();

    /// @brief Check whether the game is running
    /// @return true false
    bool isRunning();
    ~Game();
};