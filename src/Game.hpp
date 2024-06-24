#pragma once

#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Game {
  SDL_Window *window;
  SDL_Renderer *renderer;
  TTF_Font *font;

  public:
    Game();
    void loop();
    float getElapsedTime(uint32_t last_time);
};
