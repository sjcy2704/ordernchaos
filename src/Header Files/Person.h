#pragma once

#include "Player.h"
#include <iostream>
#include <fstream>

/**
 * @brief Person is a subclass from the class Player. It represents a human player in the game
 *
 */

class Person : public Player {
  public:
    /// @brief Default Constructor
    Person();

    /// @brief Displays a series of prompts to get the nickname of the player and their role
    /// @param playerNum The player number
    void dispSetNickname(int playerNum);

    /// @brief Save the current player details into a text file
    /// @param fileName The name of the file where the details will be saved
    void savePlayer(std::string fileName);

    /// @brief Load a saved player details from a text file
    /// @param fileName The name of the file where the details are loading from
    void loadPlayer(std::string fileName);
    virtual ~Person();
};