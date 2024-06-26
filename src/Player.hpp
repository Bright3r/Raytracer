

typedef struct move_direction_t {
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
} move_direction;

class Player: public Entity {
  public:
    move_direction_t *move_direction;

    Player(int x, int y, int width, int height, SDL_Color *color);
    ~Player();
    void update();
};
