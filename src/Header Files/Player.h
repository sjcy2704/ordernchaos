#pragma once

#include <string>

class Player {
  protected:
    std::string nickname;
    int points;
    std::string currToken;
    std::string currRole;
  public:
    Player();
    void incrementPoints();
    std::string getNickname();
    void setToken(std::string token);
    void setRole(std::string role);
    std::string getRole();
    void setNickname(std::string newNickname);
    std::string getToken();
    int getPoints();
    ~Player();

};