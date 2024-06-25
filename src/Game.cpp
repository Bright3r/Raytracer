
#include "Game.hpp"

const int window_width = 600;
const int window_height = 600;
const float FRAME_INTERVAL = 16.667f;

Game::Game() {
  this->window = new RenderWindow("Raycaster", window_width, window_height);
}

Game::~Game() {
  delete this->window;
}

void Game::loop() {
  Entity player;

  bool is_running = true;
  SDL_Event event;
  while (is_running) {
    uint32_t start_time = SDL_GetTicks();

    // Event handling
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        is_running = false;
      }
      else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
          case SDLK_RETURN:
            is_running = false;
            break;
          case SDLK_w:
            break;
          case SDLK_s:
            break;
          case SDLK_a:
            break;
          case SDLK_d:
            break;
        }
      }
    }

    this->window->clearScreen();
    this->window->renderEntity(player);
    this->window->present();

    // Cap framerate
    SDL_Delay(std::floor(FRAME_INTERVAL - getElapsedTime(start_time)));
  }
}

float Game::getElapsedTime(uint32_t last_time) {
  return SDL_GetTicks() - last_time;
}

