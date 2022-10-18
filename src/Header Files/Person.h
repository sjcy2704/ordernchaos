#pragma once

#include "Player.h"
#include <iostream>

class Person : public Player {
  public:
    Person();
    Person(std::string newNickname);
    void dispSetNickname(int playerNum);
    ~Person();
};