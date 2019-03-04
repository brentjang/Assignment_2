#include <iostream>
#ifndef GAME_H
#define GAME_H
#include "Board.h"

using namespace std;

class Game
{
public:
    Game() {};
    Game(int gRow, int gCol, char** board);
    ~Game() {};
    bool generateNext();
    bool empty();
    bool stable(char** board);
    void copy(char** board);
    void print();
    void write(string filename);

protected:
    Board* gameBoard;
    int gameRows;
    int gameCols;
};

#endif
