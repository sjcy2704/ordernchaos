#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

/// @brief Struct of the player choices which include token and position;
struct PlayerChoices {
  std::string token;
  int position;
};

/// @brief Gets the current token and style it then return the styled token for display
/// @param token The current token of the board
/// @return string
extern std::string getTokenStyle(std::string token);
