
#include "Game.hpp"

const char *TITLE = "Raycaster";
const int window_width = 600;
const int window_height = 600;

const float FRAME_INTERVAL = 16.667f;

Game::Game() {
  // Video
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL_Init has failed: " << SDL_GetError() << std::endl;
  }

  // Fonts
  if (TTF_Init() < 0) {
    std::cerr << "TTF_Init has failed: " << TTF_GetError() << std::endl;
  }

  this->font = TTF_OpenFont("./assets/fonts/PixelifySans-VariableFont_wght.ttf", 24);
  if (this->font == NULL) {
    std::cerr << "Failed to open font: " << TTF_GetError() << std::endl;
  }

  // Audio
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024) < 0) {
    std::cerr << "SDL_Mixer has failed: " << Mix_GetError() << std::endl;
  }

  // Window
  this->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
  if (this->window == NULL) {
    std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
  }

  // Renderer
  this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (this->renderer == NULL) {
    std::cerr << "Failed to render window: " << SDL_GetError() << std::endl;
  }
}

void Game::loop() {
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

    this->clearScreen();
    this->draw();
    SDL_RenderPresent(this->renderer);

    // Cap framerate
    SDL_Delay(std::floor(FRAME_INTERVAL - getElapsedTime(start_time)));
  }
}

float Game::getElapsedTime(uint32_t last_time) {
  return SDL_GetTicks() - last_time;
}

void Game::clearScreen() {
  setDrawColor(&COLOR_BG);
  SDL_RenderClear(this->renderer);
}

void Game::setDrawColor(SDL_Color *color) {
  SDL_SetRenderDrawColor(this->renderer, color->r, color->g, color->b, color->a);
}

void Game::draw() {
  SDL_Rect rect;
  rect.x = 100;
  rect.y = 100;
  rect.w = 100;
  rect.h = 100;

  this->setDrawColor(&COLOR_RED);
  SDL_RenderFillRect(this->renderer, &rect);
}

Game::~Game() {
  TTF_CloseFont(this->font);
  TTF_Quit();

  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);

  SDL_Quit();
  std::cout << "Successfully cleaned up game objects!" << std::endl;
}
