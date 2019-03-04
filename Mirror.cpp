#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Mirror.h"
#include "Game.h"
#include "Board.h"

using namespace std;

void Mirror::run(string out)
{
    int gen = 0;
    if(out == "1")
    {
        cout << "Generation: " << gen << endl;
        makeMirror();
        print();
        cout << '\n';

        while(generateNext() != false && gen != 1000)
        {
            this_thread::sleep_for(chrono::seconds(2));
            gen++;
            cout << "Generation: " << gen << endl;
            makeMirror();
            print();
            cout << '\n';
        }
    }
    else if(out == "2")
    {
        cin.get();
        cout << "Generation: " << gen << endl;
        makeMirror();
        print();
        cout << '\n';
        cin.get();

        while(generateNext() != false && gen != 1000)
        {
            gen++;
            cout << "Generation: " << gen << endl;
            makeMirror();
            print();
            cin.get();
        }
    }
    else if(out == "3")
    {
        string outName;
        cout << "Please enter output file name: " << endl;
        cin >> outName;
        ofstream printFile(outName, ios_base::app);
        printFile << "Generation: " << gen << endl;
        makeMirror();
        write(outName);
        printFile << endl;

        while(generateNext() != false && gen != 1000)
        {
            gen++;
            printFile << "Generation: " << gen << endl;
            makeMirror();
            write(outName);
        }
    }
    else if(out == "4") {}
    else
    {
        cout << "DEFAULT MODE [Press any key to continue...]" << endl;
        cin.get();
        cout << "Generation: " << gen << endl;
        makeMirror();
        print();
        cout << '\n';
        cin.get();

        while(generateNext() != false && gen != 1000)
        {
            gen++;
            cout << "Generation: " << gen << endl;
            makeMirror();
            print();
            cin.get();
        }
    }
    cout << "Program Exit." << endl;
}

void Mirror::makeMirror()
{
    //top row mirror
    for(int a = 1; a <= gameCols-2; a++)
    {
        if(gameBoard->genBoard[1][a] == 'X')
        {
            gameBoard->genBoard[0][a] = 'X';
        }
    }

    //bottom row mirror
    for(int b = 1; b <= gameCols-2; b++)
    {
        if(gameBoard->genBoard[gameRows-2][b] == 'X')
        {
            gameBoard->genBoard[gameRows-1][b] = 'X';
        }
    }

    //left side mirror
    for(int c = 1; c <= gameRows-2; c++)
    {
        if(gameBoard->genBoard[c][1] == 'X')
        {
            gameBoard->genBoard[c][0] = 'X';
        }
    }

    //right side mirror
    for(int d = 1; d <= gameRows-2; d++)
    {
        if(gameBoard->genBoard[d][gameCols-2] == 'X')
        {
            gameBoard->genBoard[d][gameCols-1] = 'X';
        }
    }

    //corners
    if(gameBoard->genBoard[1][1] == 'X')
    {
        gameBoard->genBoard[0][0] = 'X';
    }
    if(gameBoard->genBoard[1][gameCols-2] == 'X')
    {
        gameBoard->genBoard[0][gameCols-1] = 'X';
    }
    if(gameBoard->genBoard[gameRows-2][1] == 'X')
    {
        gameBoard->genBoard[gameRows-1][0] = 'X';
    }
    if(gameBoard->genBoard[gameRows-2][gameCols-2] == 'X')
    {
        gameBoard->genBoard[gameRows-1][gameCols-1] = 'X';
    }
}
