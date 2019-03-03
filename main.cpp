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
    int height, width;
    string input, mode, out;

    bool flag1 = false;
    bool flag2 = false;
    while(!flag1)
    {
        cout << "(1) Custom\n(2) Import File\n(3) Quit" << endl;
        cout << "Please Select Board (Enter the number next to the selection): ";
        cin >> input;

        if(input == "1")
        {
            double density;
            UserIn inputs;

            inputs.checkRows();
            inputs.checkCols();
            inputs.checkDensity();
            height = inputs.getRows();
            width = inputs.getCols();
            density = inputs.getDensity();

            Board custBoard(height, width);
            custBoard.densityFill(density);
            custBoard.printBoard();
            char** newBoard = custBoard.getBoard();

            cout << "(1) Classic\n(2) Doughnut\n(3) Mirror\n(4) Quit" << endl;
            cout << "Please Select Board Type (Enter the number next to the selection): ";
            cin >> mode;
            cout << '\n';
            cout << "(1) Pause\n(2) Enter\n(3) File\n(4) Quit" << endl;
            cout << "Please Output Type (Enter the number next to the selection): ";
            cin >> out;
            cout << '\n';

            while(!flag2)
            {
                if(mode == "1")
                {
                    Classic newClassic(height, width, newBoard);
                    newClassic.run(out);
                    flag2 = true;
                }
                else if(mode == "2")
                {
                    Doughnut newDoughnut(height, width, newBoard);
                    newDoughnut.makeDoughnut();
                    newDoughnut.run(out);
                    flag2 = true;
                }
                else if(mode == "3")
                {
                    Mirror newMirror(height, width, newBoard);
                    newMirror.makeMirror();
                    newMirror.run(out);
                    flag2 = true;
                }
                else if(mode == "4")
                {
                    flag2 = true;
                }
                else
                {
                    cout << "Invalid input." << endl;
                }
            }
            flag1 = true;
        }
        else if(input == "2")
        {
            string name;
            cout << "Please enter a file name [include extension .txt]: ";
            cin >> name;
            UserIn file;
            file.readFile(name);
            
            height = file.getRows();
            width = file.getCols();

            Board fileBoard(height, width);
            fileBoard.fileFill(name);

            char** newBoard = fileBoard.getBoard();
            cout << '\n';

            cout << "(1) Classic\n(2) Doughnut\n(3) Mirror" << endl;
            cout << "Please Select Board Type (Enter the number next to the selection): ";
            cin >> mode;
            cout << '\n';
            cout << "(1) Pause\n(2) Enter\n(3) File\n(4) Quit" << endl;
            cout << "Please Output Type (Enter the number next to the selection): ";
            cin >> out;
            cout << '\n';
            if(mode == "1")
            {
                Classic newClassic(height, width, newBoard);
                newClassic.run(out);
                flag2 = true;
            }
            else if(mode == "2")
            {
                Doughnut newDoughnut(height, width, newBoard);
                newDoughnut.run(out);
                flag2 = true;
            }
            else if(mode == "3")
            {
                Mirror newMirror(height, width, newBoard);
                newMirror.run(out);
                flag2 = true;
            }
            else if(mode == "4")
            {
                flag2 = true;
            }
            else
            {
                cout << "Invalid input." << endl;
            }
            flag1 = true;
        }
        else if (input == "3")
        {
            flag1 = true;
        }
        else
        {
            cout << "Invlid input." << endl;
        }
    }
    return 0;
}
