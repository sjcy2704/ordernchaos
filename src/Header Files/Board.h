#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

class Board {
  private:
    std::unordered_map<int, std::string> board;
    void dispBoardHelper(int currPos, std::string token);
  public:
    Board();
    void create();
    void clear();
    void displayBoard();
    void update(int position, std::string token);
    bool checkWin();
    ~Board();
};