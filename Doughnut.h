#include <iostream>
#include "Game.h"
#include "Board.h"

using namespace std;

class Doughnut: public Game
{
public:
    using Game::Game;
    void makeDoughnut();
    void run(string out);
    ~Doughnut() {};
};
