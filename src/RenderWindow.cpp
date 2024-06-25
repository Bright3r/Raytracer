
#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char *title, int window_width, int window_height) {
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
  this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
  if (this->window == NULL) {
    std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
  }

  // Renderer
  this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (this->renderer == NULL) {
    std::cerr << "Failed to render window: " << SDL_GetError() << std::endl;
  }
}

RenderWindow::~RenderWindow() {
  TTF_CloseFont(this->font);
  TTF_Quit();

  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);

  SDL_Quit();
  std::cout << "Successfully cleaned up game objects!" << std::endl;
}


void RenderWindow::setDrawColor(SDL_Color *color) {
  SDL_SetRenderDrawColor(this->renderer, color->r, color->g, color->b, color->a);
}


void RenderWindow::clearScreen() {
  setDrawColor(&COLOR_BG);
  SDL_RenderClear(this->renderer);
}


void RenderWindow::renderEntity(Entity& ent) {
  this->setDrawColor(ent.color);
  SDL_RenderFillRect(this->renderer, ent.rect);
}


void RenderWindow::present() {
  SDL_RenderPresent(this->renderer);
}
