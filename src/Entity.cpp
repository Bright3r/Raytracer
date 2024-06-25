
#include "Entity.hpp"

Entity::Entity(): x(100), y(100), width(100), height(100), color(&COLOR_RED) {
  SDL_Rect *rect = new SDL_Rect;
  rect->x = this->x;
  rect->y = this->y;
  rect->w = this->width;
  rect->h = this->height;

  this->rect = rect;
}

Entity::~Entity() {
  delete this->rect;
}
