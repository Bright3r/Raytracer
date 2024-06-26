
#include "consts.hpp"

class Entity {
  public:
    int x, y;
    int width, height;
    SDL_Rect *rect;
    SDL_Color *color;

    Entity(int x, int y, int width, int height, SDL_Color *color);
    ~Entity();
    void update();
};
