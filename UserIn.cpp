#include "UserIn.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void UserIn::readFile(string name)
{
    filename = name;
    int lineCount = 0;
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
        file.close();
    }
    else
    {
        cout << "Not a File" << endl;
    }
}

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
