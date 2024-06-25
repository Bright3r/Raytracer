#pragma once

#include <iostream>
#include "consts.hpp"
#include "Entity.cpp"


class RenderWindow {
  SDL_Window *window;
  SDL_Renderer *renderer;
  TTF_Font *font;

  public:
    RenderWindow(const char *title, int window_width, int window_height);
    ~RenderWindow();
    void setDrawColor(SDL_Color *color);
    void clearScreen();
    void renderEntity(Entity& ent);
    void present();
};
