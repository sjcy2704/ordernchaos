#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

class Board {
  private:
    std::unordered_map<int, std::string> board;
    void dispBoardHelper(int currPos, std::string token);
    void create();
  public:
    Board();
    void clear();
    void displayBoard();
    bool update(int position, std::string token);
    bool full();
    bool checkWin();
    ~Board();
};