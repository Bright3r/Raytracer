#pragma once

#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

static SDL_Color COLOR_BG = { 0, 0, 0, 255 };
static SDL_Color COLOR_BLACK = { 0, 0, 0, 255 };
static SDL_Color COLOR_WHITE = { 255, 255, 255, 255 };
static SDL_Color COLOR_LIGHT_BLUE = { 173, 216, 230, 255 };
static SDL_Color COLOR_DARK_BLUE = { 0, 0, 139, 255 };
static SDL_Color COLOR_ORANGE = { 255, 165, 0, 255 };
static SDL_Color COLOR_YELLOW = { 255, 255, 0, 255 };
static SDL_Color COLOR_GREEN = { 0, 128, 0, 255 };
static SDL_Color COLOR_PURPLE = { 128, 0, 128, 255 };
static SDL_Color COLOR_RED = { 255, 0, 0, 255 };

class Game {
  SDL_Window *window;
  SDL_Renderer *renderer;
  TTF_Font *font;

  public:
    Game();
    ~Game();
    void loop();
    float getElapsedTime(uint32_t last_time);
    void clearScreen();
    void setDrawColor(SDL_Color *color);
    void draw();
};
