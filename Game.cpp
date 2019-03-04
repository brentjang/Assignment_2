#include "Game.h"
#include "Board.h"
#include <iostream>

using namespace std;

Game::Game(int gRow, int gCol, char** board)
{
    gameRows = gRow+2;
    gameCols = gCol+2;
    gameBoard = new Board(gameRows, gameCols, board);
}

bool Game::generateNext()
{
    //initializes a board to copy onto
    char** nextBoard = new char*[gameRows];
    for(int i = 0; i < gameRows; i++)
    {
        nextBoard[i] = new char[gameCols];
    }
    for(int n = 0; n < gameRows; n++)
    {
        for(int m = 0; m < gameCols; m++)
        {
            nextBoard[n][m] = '-';
        }
    }

    //checks neighbors for next generation
    for(int x = 1; x <= gameRows-2; x++)
    {
        for(int y = 1; y <= gameCols-2; y++)
        {
            int numNeighbors = gameBoard->getNeighbors(x,y);
            if(numNeighbors <= 1)
            {
                nextBoard[x][y] = '-';
            }
            else if(numNeighbors == 2)
            {
                nextBoard[x][y] = gameBoard->genBoard[x][y];
            }
            else if(numNeighbors == 3)
            {
                nextBoard[x][y] = 'X';
            }
            else if(numNeighbors >= 4)
            {
                nextBoard[x][y] = '-';
            }
        }
    }

    //generation stops at empty, stable, or 1000 generations
    if(!empty() && !stable(nextBoard))
    {
        copy(nextBoard);
    }
    else
    {
        return false;
    }
}

//checks if whole board is empty
bool Game::empty()
{
    for(int i = 0; i < gameRows; i++)
    {
        for(int j = 0; j < gameCols; j++)
        {
            if(gameBoard->genBoard[i][j] == 'X')
            {
                return false;
            }
        }
    }
    return true;
}

//checks if the last generation is the same as new one
bool Game::stable(char** board)
{
    bool flag = true;
    for(int i = 1; i < gameRows-2; i++)
    {
        for(int j = 1; j < gameCols-2; j++)
        {
            if(board[i][j] != gameBoard->genBoard[i][j])
            {
                flag = false;
            }
        }
    }
    return flag;
}

void Game::copy(char** board)
{
    gameBoard = new Board(gameRows, gameCols, board);
}

void Game::print()
{
    cout << '\n';
    gameBoard->printBoard();
}

void Game::write(string filename)
{
    gameBoard->writeBoard(filename);
}
