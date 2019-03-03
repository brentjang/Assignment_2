#include <iostream>
#include "Game.h"
#include "Board.h"

using namespace std;

class Mirror: public Game
{
public:
    using Game::Game;
    void makeMirror();
    void run(string out);
    ~Mirror() {};
};
