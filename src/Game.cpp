
#include "Game.hpp"

const int TILE_SIZE = 30;
const int window_width = 20 * TILE_SIZE;
const int window_height = 20 * TILE_SIZE;
const float FRAME_INTERVAL = 16.667f;

Game::Game() {
  this->window = new RenderWindow("Raycaster", window_width, window_height);
}

Game::~Game() {
  delete this->window;
}

void Game::loop() {
  Player player(100, 100, 5, 5, &COLOR_RED);

  std::vector<std::vector<char>> map = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  };


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
            player.move_direction->up = true;
            break;
          case SDLK_s:
            player.move_direction->down = true;
            break;
          case SDLK_a:
            player.move_direction->left = true;
            break;
          case SDLK_d:
            player.move_direction->right = true;
            break;
        }
      }
      else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
          case SDLK_w:
            player.move_direction->up = false;
            break;
          case SDLK_s:
            player.move_direction->down = false;
            break;
          case SDLK_a:
            player.move_direction->left = false;
            break;
          case SDLK_d:
            player.move_direction->right = false;
            break;
        }
      }
    }

    player.update();
    checkCollision(map, player);

    this->window->clearScreen();
    this->window->drawMap(map, TILE_SIZE);
    this->window->renderEntity(player);
    this->window->present();

    // Cap framerate
    SDL_Delay(std::floor(FRAME_INTERVAL - getElapsedTime(start_time)));
  }
}


bool Game::checkCollision(std::vector<std::vector<char>>& map, Entity& ent) {
  for (long unsigned int i = 0; i < map.size(); i++) {
    for (long unsigned int j = 0; j < map[0].size(); j++) {
      if (!map[i][j]) continue;
      
      SDL_Rect rect;
      rect.x = i * TILE_SIZE;
      rect.y = j * TILE_SIZE;
      rect.w = TILE_SIZE;
      rect.h = TILE_SIZE;

      if (checkCollision(rect, *ent.rect)) {
        ent.color = &COLOR_YELLOW;
        return true;
      }
    }
  }

  ent.color = &COLOR_RED;
  return false;
}


bool Game::checkCollision(SDL_Rect& r1, SDL_Rect& r2) {
  if (r1.x + r1.w < r2.x || r2.x + r2.w < r1.x) {
    return false;
  }
  if (r1.y + r1.h < r2.y || r2.y + r2.h < r1.y) {
    return false;
  }

  return true; 
}


float Game::getElapsedTime(uint32_t last_time) {
  return SDL_GetTicks() - last_time;
}

