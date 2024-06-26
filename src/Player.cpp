
#include "Player.hpp"

Player::Player(int x, int y, int width, int height, SDL_Color *color) : Entity(x, y, width, height, color) {
 this->move_direction = new move_direction_t; 
}

Player::~Player() {
  delete this->move_direction;
}

void Player::update() {
  if (this->move_direction->up) {
    this->y += -10;
  }
  if (this->move_direction->down) {
    this->y += 10;
  }

  if (this->move_direction->left) {
    this->x += -10;
  }
  if (this->move_direction->right) {
    this->x += 10;
  }

  this->rect->x = this->x;
  this->rect->y = this->y;
}
