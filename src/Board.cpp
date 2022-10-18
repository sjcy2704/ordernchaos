#include "Header Files/Board.h"
#include "Header Files/Helpers.h"

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

void Board::dispBoardHelper(int currPos, std::string token) {
  if (currPos <= 9 || (token[0] == toupper('x') || token[0] == toupper('o'))) {
      if (currPos % 6 != 0) {
        std::cout << "|   " << getTokenStyle(token) << "   ";
      } else {
        std::cout << "|   " << getTokenStyle(token) << "   |";
      }
    } else if (currPos > 9) {
      if (currPos % 6 != 0) {
        std::cout << "|   " << getTokenStyle(token) << "  ";
      } else {
        std::cout << "|   " << getTokenStyle(token) << "  |";
      }
    }
    if (currPos%6 == 0) {
      std::cout << std::endl << "";
    }
}

void Board::displayBoard() {
  std::cout << "     _______________________________________________" << std::endl;
  std::cout << "    |       |       |       |       |       |       |" << std::endl;
  std::cout << "    ";

  for (int i = 1; i <= 6; i++) {
    this->dispBoardHelper(i, board[i]);
  }
  std::cout << "    |_______|_______|_______|_______|_______|_______|" << std::endl;
  std::cout << "    |       |       |       |       |       |       |" << std::endl;
  std::cout << "    ";

  for (int i = 7; i <= 12; i++) {
    this->dispBoardHelper(i, board[i]);
  }
  std::cout << "    |_______|_______|_______|_______|_______|_______|" << std::endl;
  std::cout << "    |       |       |       |       |       |       |" << std::endl;
  std::cout << "    ";

  for (int i = 13; i <= 18; i++) {
    this->dispBoardHelper(i, board[i]);
  }
  std::cout << "    |_______|_______|_______|_______|_______|_______|" << std::endl;
  std::cout << "    |       |       |       |       |       |       |" << std::endl;
  std::cout << "    ";

  for (int i = 19; i <= 24; i++) {
    this->dispBoardHelper(i, board[i]);
  }
  std::cout << "    |_______|_______|_______|_______|_______|_______|" << std::endl;
  std::cout << "    |       |       |       |       |       |       |" << std::endl;
  std::cout << "    ";

  for (int i = 25; i <= 30; i++) {
    this->dispBoardHelper(i, board[i]);
  }
  std::cout << "    |_______|_______|_______|_______|_______|_______|" << std::endl;
  std::cout << "    |       |       |       |       |       |       |" << std::endl;
  std::cout << "    ";

  for (int i = 31; i <= 36; i++) {
    this->dispBoardHelper(i, board[i]);
  }
  std::cout << "    |_______|_______|_______|_______|_______|_______|" << std::endl;

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