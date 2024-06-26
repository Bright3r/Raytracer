#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "consts.hpp"
#include "RenderWindow.cpp"
#include "Player.cpp"


class Game {
  RenderWindow *window;

  public:
    Game();
    ~Game();
    void loop();
    float getElapsedTime(uint32_t last_time);
    bool checkCollision(std::vector<std::vector<char>>& map, Entity& ent);
    bool checkCollision(SDL_Rect& r1, SDL_Rect& r2);
};
