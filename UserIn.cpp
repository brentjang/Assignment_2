#include "UserIn.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void UserIn::checkRows()
{
    cout << "Please enter number of rows: ";
    cin >> rows;
    while(cin.fail())
    {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Please enter number of rows: ";
        cin >> rows;
    }
}

void UserIn::checkCols()
{
    cout << "Please enter number of columns: ";
    cin >> cols;
    while(cin.fail())
    {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Please enter number of columns: ";
        cin >> cols;
    }
}

void UserIn::checkDensity()
{
    bool flag = false;
    cout << "Please enter population density (0,1): ";
    cin >> density;
    while(!flag)
    {
        if(!cin.fail() && (density >= 0 && density <= 1))
        {
            flag = true;
        }
        else
        {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Please enter population density (0,1): ";
            cin >> density;
        }
    }
}

void UserIn::checkInput()
{
    bool flag = false;
    cout << "(1) Custom\n(2) Import File\n(3) Quit" << endl;
    cout << "Please Select Board (Enter the number next to the selection): ";
    cin >> input;
    while(!flag)
    {
        if(!cin.fail() && (input >= 1 && input <= 4))
        {
            flag = true;
        }
        else
        {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "(1) Custom\n(2) Import File\n(3) Quit" << endl;
            cout << "Please Select Board (Enter the number next to the selection): ";
            cin >> input;
        }
    }
}

void UserIn::checkMode()
{
    bool flag = false;
    cout << "(1) Classic\n(2) Doughnut\n(3) Mirror\n(4) Quit" << endl;
    cout << "Please Select Board Type (Enter the number next to the selection): ";
    cin >> mode;
    while(!flag)
    {
        if(!cin.fail() && (mode >= 1 && mode <= 4))
        {
            flag = true;
        }
        else
        {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "(1) Classic\n(2) Doughnut\n(3) Mirror\n(4) Quit" << endl;
            cout << "Please Select Board Type (Enter the number next to the selection): ";
            cin >> mode;
        }
    }
}

void UserIn::checkOut()
{
    bool flag = false;
    cout << "(1) Pause\n(2) Enter\n(3) File\n(4) Quit" << endl;
    cout << "Please Output Type (Enter the number next to the selection): ";
    cin >> out;
    while(!flag)
    {
        if(!cin.fail() && (out >= 1 && out <= 4))
        {
            flag = true;
        }
        else
        {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "(1) Pause\n(2) Enter\n(3) File\n(4) Quit" << endl;
            cout << "Please Output Type (Enter the number next to the selection): ";
            cin >> out;
            cout << '\n';
        }
    }
}

void UserIn::readFile()
{
    bool flag = false;
    int lineCount = 0;

    while(!flag)
    {
        cout << "Please enter a file name [include extension .txt]: ";
        cin >> filename;
        ifstream file(filename);
        if(file.good())
        {
            string line;
            while(getline(file, line))
            {
                lineCount++;
                if(line.size() > 0)
                {
                    switch (lineCount)
                    {
                        case 1:
                            rows = stoi(line);
                            break;
                        case 2:
                            cols = stoi(line);
                            break;
                        default:
                            break;
                    }
                }
            }
            flag = true;
            file.close();
        }
        else
        {
            cout << "Not a File" << endl;
        }
    }
}

int UserIn::getRows()
{
    return rows;
}

int UserIn::getCols()
{
    return cols;
}

double UserIn::getDensity()
{
    return density;
}

string UserIn::getFileName()
{
    return filename;
}

int UserIn::getInput()
{
    return input;
}

int UserIn::getMode()
{
    return mode;
}

int UserIn::getOut()
{
    return out;
}
