#pragma once
#include <string>
#include <iostream>

struct PlayerChoices {
  std::string token;
  int position;
};

extern std::string getTokenStyle(std::string token);
