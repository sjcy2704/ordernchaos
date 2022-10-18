#include "Header Files/Player.h"

Player::Player() {
  this->points = 0;
  this->currToken = "";
}

/** @brief Increase the player points by 1
*/
void Player::incrementPoints() {
  this->points++;
}

/** @brief Set the current token of the player
* @param token The token to be set to the player (X or O)
*/
void Player::setToken(std::string token) {
  this->currToken = token;
}

/** @brief Set the nickname of the player
* @param newNickname The nickname to be set to the player
*/
void Player::setNickname(std::string newNickname) {
  this->nickname = newNickname;
}

/** @brief Set the current role of the player
* @param role The role to be set to the player (order or chaos)
*/
void Player::setRole(std::string role) {
  currRole = role;
}

/// @brief Get the current token of the player
/// @return X or O
std::string Player::getToken() { return this->currToken; }

/** @brief Gets the current nickname of the player
* @return "John Doe"
*/
std::string Player::getNickname() { return this->nickname; }

/** @brief Get the current points of the player
* @return int
*/
int Player::getPoints() { return this->points; }

/** @brief Get the current role of the player
* @return order chaos
*/
std::string Player::getRole() { return this->currRole; }

Player::~Player() {}