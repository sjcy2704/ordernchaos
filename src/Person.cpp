#include "Header Files/Person.h"

Person::Person() {
  this->nickname = "";
}

/** @brief Displays a series of prompts to get the nickname of the player and their role
* @param playerNum The player number
*/
void Person::dispSetNickname(int playerNum) {
  std::string nick;
  std::string role;

  if (playerNum == 1) {
    role = "order";
    std::cout << "// Order: try connect five tokens (X or O) in a row" << std::endl;
    std::cout << std::endl;
    std::cout << "Input your nickname (Order): ";
  } else {
    role = "chaos";
    std::cout << "// Chaos: prevent Order from achieving five tokens (X or O) in a row" << std::endl;
    std::cout << std::endl;
    std::cout << "Input your nickname (Chaos): ";
  }

  std::cin >> nick;

  nick[0] = toupper(nick[0]);
  this->setNickname(nick);
  this->setRole(role);
}

/** @brief Save the current player details into a text file
* @param fileName The name of the file where the details will be saved
*/
void Person::savePlayer(std::string fileName) {
  std::ofstream playertxt("build/saveFolder/" + fileName);

  playertxt << this->nickname << std::endl;
  playertxt << this->currRole << std::endl;
  playertxt << this->points << std::endl;

  playertxt.close();
}

/** @brief Load a saved player details from a text file
* @param fileName The name of the file where the details are loading from
*/
void Person::loadPlayer(std::string fileName) {
  std::ifstream playertxt("build/saveFolder/" + fileName);

  std::string container[3] = {};

  for (int i = 0; i < 3; i++) {
    playertxt >> container[i];
  }

  this->nickname = container[0];
  this->currRole = container[1];
  this->points = std::stoi(container[2]);

  playertxt.close();
}

Person::~Person() {}