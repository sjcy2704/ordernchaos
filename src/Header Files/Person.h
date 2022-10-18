#pragma once

#include "Player.h"
#include <iostream>
#include <fstream>

class Person : public Player {
  public:
    Person();
    Person(std::string newNickname);
    void dispSetNickname(int playerNum);
    void savePlayer(std::string fileName);
    void loadPlayer(std::string fileName);
    virtual ~Person();
};