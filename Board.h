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
    char** getBoard();
    int getRows();
    int getCols();
    void fileFill(string name);
    void densityFill(double density);
    void printBoard();
    void writeBoard(string filename);
    int getNeighbors(int x, int y);
};

#endif
