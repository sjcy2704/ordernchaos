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
  this->setNickname(nick);
  this->setRole(role);
}

Person::~Person() {}