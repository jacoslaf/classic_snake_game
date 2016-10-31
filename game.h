#include "snake.h"

class Game {
public:
    int height;
    int width;

    Point apple;
    Snake *snake;

    Game(int height, int width);
    void SetupApplePosition();
    void Move();
};
