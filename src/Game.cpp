#include "Header Files/Game.h"

Game::Game() {
  running = false;
}

void Game::setRunning(bool value) {
  running = value;
}

void Game::run() {
  while (this->isRunning()) {
  }
}

bool Game::isRunning() { return running; }

void Game::displayBoard() {
  this->board.displayBoard();
}

Game::~Game() {}