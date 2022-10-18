#include "Header Files/Helpers.h"

std::string getTokenStyle(std::string token) {
  std::string styledToken;

  if (token == "X" || token == "O") {
    styledToken = "\e[1m" + token + "\e[0m";
  } else {
    styledToken = "\e[1m\e[2m\e[4m" + token + "\e[0m";
  }

  return styledToken;
}