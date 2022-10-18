#include "Header Files/Game.h"

Game::Game() {
  running = false;
}

void Game::setRunning(bool value) {
  running = value;
}

void Game::screenClear() {
  system("clear");
}

void Game::dispIntro() {
  std::cout << std::endl;

  std::cout << "*---------------  W E L C O M E  -  T O  -  O R D E R  -  A N D  -  C H A O S  ---------------*" << std::endl;

  std::cout << std::endl;

  std::cout << "// How to play: 2 players, both can choose to place an 'X' or an 'O'. There are 2 roles:" << std::endl;

  std::cout << "   - Order: try to connect five tokens (X or O) in a row" << std::endl;
  std::cout << "   - Chaos: prevent Order from achieving five tokens in a row" << std::endl;

  std::cout << std::endl;
}

void Game::dispMenu() {
  std::cout << "1. Play Order and Chaos (2 players)" << std::endl;
  std::cout << "2. Scoreboard" << std::endl;
  std::cout << "3. How to play Order and Chaos" << std::endl;
  std::cout << "4. Quit" << std::endl;

  std::cout << std::endl;
}

int Game::getMenuChoice() {
  int choice;

  while (true) {
    std::cout << "Choose your option: ";
    std::cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > 4) {
      this->screenClear();
      this->dispIntro();
      this->dispMenu();
      std::cout << "Wrong choice please input one of the options above..." << std::endl;
      std::cin.clear();
      std::cin.ignore(256,'\n');
    } else {
      break;
    }
  };

  return choice;
}

void Game::gameOver() {
  this->screenClear();

  std::cout << "!-!-!-!-------  T H A N K  Y O U  F O R  P L A Y I N G  -------!-!-!-!" << std::endl;

  std::cout << std::endl;
}

PlayerChoices Game::getPlayerChoices(Person player) {
  std::string choiceToken;
  std::string playerRole = player.getRole();
  playerRole[0] = toupper(playerRole[0]);

  while (toupper(choiceToken[0]) != toupper('x') && toupper(choiceToken[0]) != toupper('o')) {
    std::cout << player.getNickname() << " ("<< playerRole << ") choose the token (X or O): ";
    std::cin >> choiceToken;
    if (choiceToken.length() > 1 || (toupper(choiceToken[0]) != toupper('x') && toupper(choiceToken[0]) != toupper('o'))) {
      this->screenClear();
      std::cout << std::endl;
      board.displayBoard();
      std::cout << std::endl;
      std::cout << "Please make sure you input the correct token (X or O)" << std::endl;
    }
  }

  choiceToken[0] = toupper(choiceToken[0]);

  this->screenClear();
  std::cout << std::endl;
  board.displayBoard();
  std::cout << std::endl;

  int position = 0;

  while (position < 1 || position > 36) {
    std::cout << player.getNickname() << " ("<< playerRole << ") please choose a number between 1 and 36: ";
    std::cin >> position;
    if (std::cin.fail() || position < 1 || position > 36) {
      this->screenClear();
      std::cout << std::endl;
      board.displayBoard();
      std::cout << std::endl;
      std::cout << "Please enter a correct value i.e. a number between 1 and 36..." << std::endl;
      std::cin.clear();
      std::cin.ignore(256,'\n');
    }
  }

  return { choiceToken, position };
}

void Game::createPlayers() {
  this->screenClear();
  player1.dispSetNickname(1);
  this->screenClear();
  player2.dispSetNickname(2);
}

void Game::run() {
  this->screenClear();

  this->dispIntro();

  this->dispMenu();

  int choice = this->getMenuChoice();

  if (choice == 1) {
    this->setRunning(true);
    this->createPlayers();
  } else if (choice == 4) {
    this->gameOver();
  }

  while (this->isRunning()) {
    this->displayBoard();

    PlayerChoices playerChoices = this->getPlayerChoices(player1);

    board.update(playerChoices.position, playerChoices.token);

    this->displayBoard();

    playerChoices = this->getPlayerChoices(player2);

    board.update(playerChoices.position, playerChoices.token);

  }

}

bool Game::isRunning() { return running; }

void Game::displayBoard() {
  this->screenClear();

  std::cout << std::endl;

  this->board.displayBoard();

  std::cout << std::endl;
}

Game::~Game() {}