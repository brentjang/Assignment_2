#include <iostream>
#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board
{
public:
    string filename;
    int rows;
    int cols;
    double density;
    char** genBoard;

    Board();
    Board(int r, int c);
    Board(int r, int c, char** board);
    ~Board();
    void densityFill(double density);
    void fileFill(string name);
    int getNeighbors(int x, int y);
    void printBoard();
    void writeBoard(string filename);
    char** getBoard();
    int getRows();
    int getCols();
};

#endif
