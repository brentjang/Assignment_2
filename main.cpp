#include "Board.h"
#include "UserIn.h"
#include "Classic.h"
#include "Mirror.h"
#include "Doughnut.h"
#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    UserIn inputs;
    int height, width, mode, out, input;

    inputs.checkInput();
    input = inputs.getInput();

    //randomly generated board
    if(input == 1)
    {
        double density;

        inputs.checkRows();
        inputs.checkCols();
        inputs.checkDensity();
        height = inputs.getRows();
        width = inputs.getCols();
        density = inputs.getDensity();

        Board custBoard(height, width);
        custBoard.densityFill(density);
        char** newBoard = custBoard.getBoard();

        inputs.checkMode();
        mode = inputs.getMode();

        inputs.checkOut();
        out = inputs.getOut();

        if(mode == 1)
        {
            Classic newClassic(height, width, newBoard);
            newClassic.run(out);
        }
        else if(mode == 2)
        {
            Doughnut newDoughnut(height, width, newBoard);
            newDoughnut.makeDoughnut();
            newDoughnut.run(out);
        }
        else if(mode == 3)
        {
            Mirror newMirror(height, width, newBoard);
            newMirror.makeMirror();
            newMirror.run(out);

        }
        else if(mode == 4) {}
        else
        {
            cout << "Invalid input." << endl;
        }
    }

    //User imported board
    else if(input == 2)
    {
        UserIn file;
        file.readFile();

        height = file.getRows();
        width = file.getCols();

        Board fileBoard(height, width);
        fileBoard.fileFill(file.getFileName());
        char** newBoard = fileBoard.getBoard();

        inputs.checkMode();
        mode = inputs.getMode();

        inputs.checkOut();
        out = inputs.getOut();

        if(mode == 1)
        {
            Classic newClassic(height, width, newBoard);
            newClassic.run(out);
        }
        else if(mode == 2)
        {
            Doughnut newDoughnut(height, width, newBoard);
            newDoughnut.run(out);
        }
        else if(mode == 3)
        {
            Mirror newMirror(height, width, newBoard);
            newMirror.run(out);
        }
        else if(mode == 4) {}
        else
        {
            cout << "Invalid input." << endl;
        }
    }
    //(3) is to exit
    else if (input == 3) {}
    return 0;
}
