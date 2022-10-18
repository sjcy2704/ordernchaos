#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

/**
 * @brief Board class initialises an unordered_map to map out the current positions of the board and include functions to update the board, check if the board is full, and check if there are five tokens connected
 *
 */

class Board {
  private:
    /// @brief The board map
    std::unordered_map<int, std::string> board;

    /// @brief Helper function to display the board
    /// @param currPos The current position of the board
    /// @param token The current token on the board
    void dispBoardHelper(int currPos, std::string token);

    /// @brief Reinitialise the empty board
    void create();
  public:
    /// @brief Constructor
    Board();

    /// @brief Clear all the board
    void clear();

    /// @brief Displays the board
    void displayBoard();

    /// @brief Updates the position given by the parameter position with the token given by the parameter token
    /// @param position The position in the board
    /// @param token The token to put in the board (X or O)
    /// @return true false
    bool update(int position, std::string token);

    /// @brief Iterates through the board to check if there are five tokens aligned
    /// @return true false
    bool checkWin();

    /// @brief Check whether the board is full with tokens
    /// @return true false
    bool full();

    /// @brief Save the current board into a text file
    void saveMap();

    /// @brief Load the a saved board into the current board
    void loadMap();

    /// @brief Destructor
    ~Board();
};