

{
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 0, 0, 1, 1, 0, 1 },
  { 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
}

class Map {
  char **tiles;

  public:
    Map();
    ~Map();
};