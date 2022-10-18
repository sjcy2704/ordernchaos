#include "Header Files/Person.h"

Person::Person() {
  this->nickname = "";
}

Person::Person(std::string newNickname) {
  this->nickname = newNickname;
}

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

void Person::savePlayer(std::string fileName) {
  std::ofstream playertxt("build/saveFolder/" + fileName);

  playertxt << this->nickname << std::endl;
  playertxt << this->currRole << std::endl;
  playertxt << this->points << std::endl;

  playertxt.close();
}

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