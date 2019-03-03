#include <iostream>
#include "Game.h"
#include "Board.h"

using namespace std;

class Classic: public Game
{
public:
    using Game::Game;
    void run(string out);
    ~Classic() {};
};
