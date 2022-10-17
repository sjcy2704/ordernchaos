#include <iostream>
#include <unordered_map>
#include "Header Files/Board.h"

Board::Board() {
  for (int i = 1; i <= 36; i++) {
    board[i] = std::to_string(i);
  }
}

void Board::create() {
  for (int i = 1; i <= 36; i++) {
    board[i] = std::to_string(i);
  }
}

void Board::clear() {
  board.empty();
  this->create();
}

void Board::displayBoard() {
  std::cout <<"       |       |       |       |       |        " << std::endl;
  for (int i = 1; i <= 6; i++) {
    if (i <= 9 || (board[i] == "x" || board[i] == "o")) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "   ";
      } else {
        std::cout << "   " << board[i] << "   |";
      }
    } else if (i > 9) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "  ";
      } else {
        std::cout << "   " << board[i] << "  |";
      }
    }
    if (i%6 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout <<"_______|_______|_______|_______|_______|_______" << std::endl;
  std::cout <<"       |       |       |       |       |        " << std::endl;
  for (int i = 7; i <= 12; i++) {
    if (i <= 9 || (board[i] == "x" || board[i] == "o")) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "   ";
      } else {
        std::cout << "   " << board[i] << "   |";
      }
    } else if (i > 9) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "  ";
      } else {
        std::cout << "   " << board[i] << "  |";
      }
    }
    if (i%6 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout <<"_______|_______|_______|_______|_______|_______" << std::endl;
  std::cout <<"       |       |       |       |       |        " << std::endl;
  for (int i = 13; i <= 18; i++) {
    if (i <= 9 || (board[i] == "x" || board[i] == "o")) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "   ";
      } else {
        std::cout << "   " << board[i] << "   |";
      }
    } else if (i > 9) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "  ";
      } else {
        std::cout << "   " << board[i] << "  |";
      }
    }
    if (i%6 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout <<"_______|_______|_______|_______|_______|_______" << std::endl;
  std::cout <<"       |       |       |       |       |        " << std::endl;
  for (int i = 19; i <= 24; i++) {
    if (i <= 9 || (board[i] == "x" || board[i] == "o")) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "   ";
      } else {
        std::cout << "   " << board[i] << "   |";
      }
    } else if (i > 9) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "  ";
      } else {
        std::cout << "   " << board[i] << "  |";
      }
    }
    if (i%6 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout <<"_______|_______|_______|_______|_______|_______" << std::endl;
  std::cout <<"       |       |       |       |       |        " << std::endl;
  for (int i = 25; i <= 30; i++) {
    if (i <= 9 || (board[i] == "x" || board[i] == "o")) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "   ";
      } else {
        std::cout << "   " << board[i] << "   |";
      }
    } else if (i > 9) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "  ";
      } else {
        std::cout << "   " << board[i] << "  |";
      }
    }
    if (i%6 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout <<"_______|_______|_______|_______|_______|_______" << std::endl;
  std::cout <<"       |       |       |       |       |        " << std::endl;
  for (int i = 31; i <= 36; i++) {
    if (i <= 9 || (board[i] == "x" || board[i] == "o")) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "   ";
      } else {
        std::cout << "   " << board[i] << "   |";
      }
    } else if (i > 9) {
      if (i % 6 == 0) {
        std::cout << "   " << board[i] << "  ";
      } else {
        std::cout << "   " << board[i] << "  |";
      }
    }
    if (i%6 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout <<"       |       |       |       |       |       " << std::endl;

}

void Board::update(int position, std::string token) {
  if (position <= 36 && position >= 1) {
    board[position] = token;
  }
}

bool Board::checkWin() {
  int directionsWin[4] = { 1, 6, 7, 5 };
  int counterCons = 0;

  for (int pos = 1; pos <= 12; pos++) {
    int temp = pos;
    if (board[temp] != "0") {
      for (int direc = 0; direc < 4; direc++) {
        for (int i = 0; i < 4; i++) {
          if (board[temp] == board[temp+directionsWin[direc]]) {
            counterCons++;
          } else {
            counterCons = 0;
            break;
          }
          temp += directionsWin[direc];
        }

        if (counterCons >= 4) {
          return true;
        }
      }
    }
  }

  if (counterCons >= 4) {
    return true;
  }

  return false;
}

Board::~Board() {}