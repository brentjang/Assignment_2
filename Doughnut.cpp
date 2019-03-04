#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Doughnut.h"
#include "Game.h"
#include "Board.h"

using namespace std;

void Doughnut::makeDoughnut()
{
    //top row wrap to bottom
    for(int a = 1; a <= gameCols-2; a++)
    {
        if(gameBoard->genBoard[1][a] == 'X')
        {
            gameBoard->genBoard[gameRows-1][a] = 'X';
        }
    }

    //bottom row wrap to top
    for(int b = 1; b <= gameCols-2; b++)
    {
        if(gameBoard->genBoard[gameRows-2][b] == 'X')
        {
            gameBoard->genBoard[0][b] = 'X';
        }
    }

    //left side wrap to right
    for(int c = 1; c <= gameRows-2; c++)
    {
        if(gameBoard->genBoard[c][1] == 'X')
        {
            gameBoard->genBoard[c][gameCols-1] = 'X';
        }
    }

    //right side wrap to left
    for(int d = 1; d <= gameRows-2; d++)
    {
        if(gameBoard->genBoard[d][gameCols-2] == 'X')
        {
            gameBoard->genBoard[d][0] = 'X';
        }
    }

    //corners
    if(gameBoard->genBoard[1][1] == 'X')
    {
        gameBoard->genBoard[gameRows-1][gameCols-1] = 'X';
    }
    if(gameBoard->genBoard[1][gameCols-2] == 'X')
    {
        gameBoard->genBoard[gameRows-1][0] = 'X';
    }
    if(gameBoard->genBoard[gameRows-2][1] == 'X')
    {
        gameBoard->genBoard[0][gameCols-1] = 'X';
    }
    if(gameBoard->genBoard[gameRows-2][gameCols-2] == 'X')
    {
        gameBoard->genBoard[0][0] = 'X';
    }
}

void Doughnut::run(int out)
{
    int gen = 0;

    //pause between generations
    if(out == 1)
    {
        cout << "Generation: " << gen << endl;
        makeDoughnut();
        print();
        cout << '\n';

        while(generateNext() != false && gen != 1000)
        {
            this_thread::sleep_for(chrono::seconds(2));
            gen++;
            cout << "Generation: " << gen << endl;
            makeDoughnut();
            print();
            cout << '\n';
        }
    }

    //get key before next generation
    else if(out == 2)
    {
        cin.get();
        cout << "Generation: " << gen << endl;
        makeDoughnut();
        print();
        cout << '\n';
        cin.get();

        while(generateNext() != false && gen != 1000)
        {
            gen++;
            cout << "Generation: " << gen << endl;
            makeDoughnut();
            print();
            cin.get();
        }
    }

    //output to file
    else if(out == 3)
    {
        string outName;
        cout << "Please enter output file name: " << endl;
        cin >> outName;
        ofstream printFile(outName, ios_base::app);
        printFile << "Generation: " << gen << endl;
        makeDoughnut();
        write(outName);
        printFile << endl;

        while(generateNext() != false && gen != 1000)
        {
            gen++;
            printFile << "Generation: " << gen << endl;
            makeDoughnut();
            write(outName);
        }
    }
    else if(out == 4) {}
    else
    {
        cout << "DEFAULT MODE [Press any key to continue...]" << endl;
        cin.get();
        cout << "Generation: " << gen << endl;
        makeDoughnut();
        print();
        cout << '\n';
        cin.get();

        while(generateNext() != false && gen != 1000)
        {
            gen++;
            cout << "Generation: " << gen << endl;
            makeDoughnut();
            print();
            cin.get();
        }
    }
    cout << "Program Exit." << endl;
}
