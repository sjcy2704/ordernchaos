#include "Header Files/Helpers.h"

/** @brief Gets the current token and style it then return the styled token for display
* @param token The current token of the board
* @return string
*/
std::string getTokenStyle(std::string token) {
  std::string styledToken;

  if (token == "X" || token == "O") {
    styledToken = "\e[1m" + token + "\e[0m";
  } else {
    styledToken = "\e[1m\e[2m\e[4m" + token + "\e[0m";
  }

  return styledToken;
}
