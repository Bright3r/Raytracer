#pragma once

#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "consts.hpp"
#include "RenderWindow.cpp"

class Game {
  RenderWindow *window;

  public:
    Game();
    ~Game();
    void loop();
    float getElapsedTime(uint32_t last_time);
};
