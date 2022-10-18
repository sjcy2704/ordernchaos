#include "Header Files/Game.h"

Game::Game() {
  running = false;
  autosave = false;
  turns = 0;
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

bool Game::getSaveStatus() {
  bool savedStatus = false;

  if (std::__fs::filesystem::exists("build/saveFolder")) {
    std::ifstream savetxt("build/saveFolder/save.txt");

    savetxt >> savedStatus;
  }


  return savedStatus;
}

void Game::dispMenu() {
  bool savedStatus = this->getSaveStatus();

  if (savedStatus) {
    std::cout << "1. Continue last game" << std::endl;
    std::cout << "2. New Order and Chaos game" << std::endl;
    std::cout << "3. Quit" << std::endl;
  } else {
    std::cout << "1. Play Order and Chaos (2 players)" << std::endl;
    std::cout << "2. Quit" << std::endl;
  }

  std::cout << std::endl;
}

int Game::getMenuChoice() {
  int choice = 0;

  bool savedStatus = this->getSaveStatus();

  int limit;

  limit = savedStatus ? 3 : 2;

  while (choice < 1 || choice > limit) {
    std::cout << "Choose your option: ";
    std::cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > limit) {
      this->screenClear();
      this->dispIntro();
      this->dispMenu();
      std::cout << "Wrong choice please input one of the options above..." << std::endl;
      std::cin.clear();
      std::cin.ignore(256,'\n');
    }
  };

  if (savedStatus) {
    if (choice == 1) {
      this->load();
      this->setRunning(true);
    } else if (choice == 2) {
      this->clearSave();
      this->setRunning(true);
      this->createPlayers();
      this->board.clear();
    } else {
      this->gameOver();
    }
  } else {
    if (choice == 1) {
      this->setRunning(true);
      this->createPlayers();
      this->board.clear();
    } else {
      this->gameOver();
    }
  }

  return choice;
}

void Game::dispScoreboard() {
  std::cout << "      |   " << playerList[0].getNickname() << ":  " << playerList[0].getPoints() << "   v   " << playerList[1].getNickname() << ":  " << playerList[1].getPoints() << "   |" << std::endl;
}

void Game::gameOver() {
  this->screenClear();

  if (this->turns > 0) {
    std::cout << "*----------------------  F I N A L  S C O R E ----------------------*" << std::endl;

    std::cout << std::endl;

    std::cout << "        ";

    this->dispScoreboard();
  }

  std::cout << std::endl;

  std::cout << "!-!-!-!-------  T H A N K  Y O U  F O R  P L A Y I N G  -------!-!-!-!" << std::endl;

  std::cout << std::endl;
}

void Game::changeRole() {
  std::swap(playerList[0], playerList[1]);

  playerList[0].setRole("order");
  playerList[1].setRole("chaos");
}

PlayerChoices Game::getPlayerChoices(Person& player, bool badChoice) {
  std::string choiceToken;
  std::string playerRole = player.getRole();
  playerRole[0] = toupper(playerRole[0]);

  if (!badChoice) {
    while (toupper(choiceToken[0]) != toupper('x') && toupper(choiceToken[0]) != toupper('o') || choiceToken.length() > 1) {
      std::cout << player.getNickname() << " ("<< playerRole << ") choose the token (X or O): ";
      std::cin >> choiceToken;

      if (choiceToken.length() > 1 || (toupper(choiceToken[0]) != toupper('x') && toupper(choiceToken[0]) != toupper('o'))) {
        this->displayBoard();
        std::cout << "Please make sure you input the correct token (X or O)" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
      }
    }

    choiceToken[0] = toupper(choiceToken[0]);
    player.setToken(choiceToken);
  }

  choiceToken = player.getToken();

  int position = 0;

  while (position < 1 || position > 36) {
    std::cout << player.getNickname() << " ("<< playerRole << ") please choose the number of the position you wish to put your token: ";
    std::cin >> position;
    if (std::cin.fail() || position < 1 || position > 36) {
      this->screenClear();
      this->displayBoard();
      std::cout << "Please enter a correct value i.e. a number between 1 and 36..." << std::endl;
      std::cin.clear();
      std::cin.ignore(256,'\n');
    }
  }

  return { choiceToken, position };
}

void Game::createPlayers() {
  playerList = new Person[2];

  Person player1;
  Person player2;

  this->screenClear();
  player1.dispSetNickname(1);
  this->screenClear();
  player2.dispSetNickname(2);

  playerList[0] = player1;
  playerList[1] = player2;
}

void Game::run() {
  this->screenClear();

  this->dispIntro();

  this->dispMenu();

  this->getMenuChoice();

  this->askToSave();

  while (this->isRunning()) {
    this->displayBoard();

    this->turns++;

    for (int i = 0; i < 2; i++) {
      if (this->turns % 2 == 0) {
        i++;
      }
      PlayerChoices playerChoices = this->getPlayerChoices(playerList[i]);
      bool updtStatus = board.update(playerChoices.position, playerChoices.token);

      while (!updtStatus) {
        this->displayBoard();

        std::cout << "Current choice (" << playerChoices.position << ") is occupied. Please choose another position..." << std::endl;

        playerChoices = this->getPlayerChoices(playerList[i], true);
        updtStatus = board.update(playerChoices.position, playerChoices.token);
      }

      if (this->autosave) {
        this->save();
      }

      if (this->board.checkWin()) {
        break;
      };

      this->displayBoard();

    }

    bool currState = this->checkWin();

    if (currState) {
      this->dispOutro();
    }

  }
}

void Game::askToSave() {
  this->screenClear();
  int choice = 0;

  while (choice != 1 && choice != 2) {
    std::cout << "Would you like to auto-save the current game?" << std::endl;
    std::cout << "1. Yes" << std::endl << "2. No" << std::endl;

    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 2) {
      std::cout << "Please enter a valid input..." << std::endl;
      std::cout << std::endl;

      std::cin.clear();
      std::cin.ignore(256,'\n');
    }
  }

  if (choice == 1) {
    this->autosave = true;
  } else {
    this->clearSave();
  }
}

void Game::dispOutro() {

  int choice = 0;

  while (choice != 1 && choice != 2) {
    std::cout << "Would you like to continue playing?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. Quit" << std:: endl;

    std::cout << std::endl;

    std::cout << "Enter your choice: ";

    std::cin >> choice;

    if (std::cin.fail() || choice != 1 || choice != 2) {
      this->checkWin();

      std::cout << "Wrong input, please input a valid option..." << std::endl;
      std::cin.clear();
      std::cin.ignore(256,'\n');
    }

  }

  this->previousWinner->incrementPoints();

  if (choice == 2) {
    this->setRunning(false);
    this->gameOver();
  } else {
    this->changeRole();
    this->board.clear();
  }
}

bool Game::checkWin() {
  this->displayBoard();

  for (int i = 0; i < 2; i++) {
    if (this->board.checkWin()) {
      if (this->playerList[i].getRole() == "order") {
        std::cout << "Congratulations " << this->playerList[i].getNickname() << " (Order), you've succeded to maintain everything in order and connected five in a row!!!" << std::endl;
        std::cout << std::endl;
        previousWinner = &this->playerList[i];
        return true;
      }
    } else if (this->board.full() && !this->board.checkWin()) {
      std::cout << "Congratulations " << this->playerList[i].getNickname() << " (Chaos), you've successfully wreaked havoc and stopped Order from connecting five in a row!!!" << std::endl;
      previousWinner = &this->playerList[i];
      std::cout << std::endl;
      return true;
    }
  }
  return false;
}

bool Game::isRunning() { return running; }

void Game::displayBoard() {
  this->screenClear();

  if (this->autosave) {
    std::cout << std::endl;
    std::cout << "To exit with current game press key combo CTRL+C" << std::endl;
    std::cout << std::endl;
  }

  this->dispScoreboard();

  std::cout << std::endl;

  this->board.displayBoard();

  std::cout << std::endl;
}

void Game::clearSave() {
  std::ofstream ofs;
  ofs.open("build/saveFolder/map.txt", std::ofstream::out | std::ofstream::trunc);
  ofs.close();

  ofs.open("build/saveFolder/player0.txt", std::ofstream::out | std::ofstream::trunc);
  ofs.close();

  ofs.open("build/saveFolder/player1.txt", std::ofstream::out | std::ofstream::trunc);
  ofs.close();

  this->setSaveStatus(false);
}

void Game::setSaveStatus(bool value) {
  std::ofstream savetxt("build/saveFolder/save.txt");

  savetxt << value;
  savetxt << this->turns;

  savetxt.close();
}

void Game::save() {
  if (!std::__fs::filesystem::exists("build/saveFolder")) {
    system("mkdir build/saveFolder");
  }

  this->setSaveStatus(true);

  this->board.saveMap();

  for (int i = 0; i < 2; i++) {
    playerList[i].savePlayer("player" + std::to_string(i) + ".txt");
  }
}

void Game::load() {
  std::ifstream savetxt("build/saveFolder/save.txt");
  
  for(int i = 0; i < 2; i++) {
    savetxt >> this->turns;
  }

  this->board.loadMap();

  playerList = new Person[2];

  Person player1;
  Person player2;

  player1.loadPlayer("player0.txt");
  player2.loadPlayer("player1.txt");

  playerList[0] = player1;
  playerList[1] = player2;
}

Game::~Game() {
  delete [] playerList;
}