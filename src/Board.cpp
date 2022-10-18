#include "Header Files/Board.h"
#include "Header Files/Helpers.h"

Board::Board() {
  for (int i = 1; i <= 36; i++) {
    board[i] = std::to_string(i);
  }
}

/**
 * @brief Reinitialise the empty board
 *
 */
void Board::create() {
  for (int i = 1; i <= 36; i++) {
    board[i] = std::to_string(i);
  }
}

/**
 * @brief Helper function to display the board
 *
 * @param currPos The current position of the board
 * @param token The current token on the board
 */
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

/**
 * @brief Clear all the board
 *
 */
void Board::clear() {
  board.empty();
  this->create();
}

/**
* @brief Displays the board
*
*/
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

/**
 * @brief Updates the position given by the parameter position with the token given by the parameter token
 *
 * @param position The position in the board
 * @param token The token to put in the board (X or O)
 * @return true
 * @return false
 */

bool Board::update(int position, std::string token) {
  if (board[position] == "X" || board[position] == "O") {
    return false;
  }

  board[position] = token;
  return true;
}

/**
 * @brief Iterates through the board to check if there are five tokens aligned
 *
 * @return true
 * @return false
 */
bool Board::checkWin() {
  int directionsWin[4] = { 1, 6, 7, 5 };
  int counterCons = 0;

  for (int pos = 1; pos <= 36; pos++) {
    int temp = pos;
    for (int direc = 0; direc < 4; direc++) {
      for (int i = 0; i < 4; i++) {
        if (board[temp] == board[temp+directionsWin[direc]]) {
          counterCons++;
          if (counterCons > 4) {
            return true;
          }
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

  if (counterCons >= 4) {
    return true;
  }

  return false;
}

/**
 * @brief Check whether the board is full with tokens
 *
 * @return true
 * @return false
 */
bool Board::full() {
  for (int i = 1; i <= 36; i++) {
    if (board[i] != "X" || board[i] != "O") {
      return false;
    }
  }

  return true;
}

/**
 * @brief Save the current board into a text file
 *
 */
void Board::saveMap() {
  std::ofstream boardMap("build/saveFolder/map.txt");

  for (auto pos : board) {
    boardMap << pos.second << std::endl;
  }

  boardMap.close();
}

/**
 * @brief Load the a saved board into the current board
 *
 */
void Board::loadMap() {
  std::ifstream boardMap("build/saveFolder/map.txt");

  std::string token;

  for (int i = 36; i >= 1; i--) {
    boardMap >> token;
    board[i] = token;
  }

  boardMap.close();
}

Board::~Board() {}