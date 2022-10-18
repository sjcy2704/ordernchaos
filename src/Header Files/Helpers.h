#pragma once
#include <string>

struct PlayerChoices {
  std::string token;
  int position;
};

extern std::string getTokenStyle(std::string token);