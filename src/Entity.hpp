
#include "consts.hpp"

class Entity {
  public:
    int x, y;
    int width, height;
    SDL_Rect *rect;
    SDL_Color *color;

    Entity();
    ~Entity();
};
