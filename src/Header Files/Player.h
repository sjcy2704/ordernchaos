#pragma once

#include <string>

class Player {
  protected:
    /// @brief Player nickname
    std::string nickname;

    /// @brief Player points
    int points;

    /// @brief Player current token
    std::string currToken;

    /// @brief Player current role
    std::string currRole;
  public:
    /// @brief Default Constructor
    Player();

    /// @brief Increase the player points by 1;
    void incrementPoints();

    /// @brief Gets the current nickname of the player
    /// @return "John Doe"
    std::string getNickname();

    /// @brief Set the current token of the player
    /// @param token The token to be set to the player (X or O)
    void setToken(std::string token);

    /// @brief Set the current role of the player
    /// @param role The role to be set to the player (order or chaos)
    void setRole(std::string role);

    /// @brief Get the current role of the player
    /// @return order chaos
    std::string getRole();

    /// @brief Set the nickname of the player
    /// @param newNickname The nickname to be set to the player
    void setNickname(std::string newNickname);

    /// @brief Get the current token of the player
    /// @return X or O
    std::string getToken();

    /// @brief Get the current points of the player
    /// @return int
    int getPoints();

    /// @brief Save the current player details into a text file
    /// @param fileName The name of the file where the details will be saved
    virtual void savePlayer(std::string fileName) = 0;

    /// @brief Load a saved player details from a text file
    /// @param fileName The name of the file where the details are loading from
    virtual void loadPlayer(std::string fileName) = 0;
    virtual ~Player();

};