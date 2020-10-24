#ifndef GAME_H
#define GAME_H
#include "run.hpp"

class Game
{
public:
    Game();
    ~Game();

    void show();
    void start();
private:
    int a[4][4] = {0};
};

#endif // GAME_H
