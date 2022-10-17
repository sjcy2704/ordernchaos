#pragma once

#include <unordered_map>
#include <string>

class Board {
  private:
    std::unordered_map<int, std::string> board;
  public:
    Board();
    void create();
    void clear();
    void displayBoard();
    void update(int position, std::string token);
    bool checkWin();
    ~Board();
};