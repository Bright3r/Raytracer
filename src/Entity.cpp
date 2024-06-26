
#include "Entity.hpp"


Entity::Entity(int x, int y, int width, int height, SDL_Color *color) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->color = color;

  SDL_Rect *rect = new SDL_Rect;
  rect->x = x;
  rect->y = y;
  rect->w = width;
  rect->h = height;

  this->rect = rect;
}

Entity::~Entity() {
  delete this->rect;
}

void Entity::update() {
  this->rect->x = this->x;
  this->rect->y = this->y;
}
