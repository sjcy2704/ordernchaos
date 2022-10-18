#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

struct PlayerChoices {
  std::string token;
  int position;
};

extern std::string getTokenStyle(std::string token);
