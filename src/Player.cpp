#include "Header Files/Player.h"

Player::Player() {
  this->points = 0;
  this->currToken = "";
}

void Player::setToken(std::string token) {
  this->currToken = token;
}

void Player::setNickname(std::string newNickname) {
  this->nickname = newNickname;
}

void Player::updtPoints() {
  this->points++;
}

void Player::setRole(std::string role) {
  currRole = role;
}

std::string Player::getToken() { return this->currToken; }

std::string Player::getNickname() { return this->nickname; }

int Player::getPoints() { return this->points; }

std::string Player::getRole() { return this->currRole; }

Player::~Player() {}