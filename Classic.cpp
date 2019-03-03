#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Classic.h"
#include "Game.h"
#include "Board.h"

using namespace std;

void Classic::run(string out)
{
    int gen = 0;
    if(out == "1")
    {
        cout << "Generation: " << gen << endl;
        print();
        cout << '\n';

        while(generateNext() != false)
        {
            this_thread::sleep_for(chrono::seconds(2));
            gen++;
            cout << "Generation: " << gen << endl;
            print();
            cout << '\n';
        }
    }
    else if(out == "2")
    {
        cin.get();
        cout << "Generation: " << gen << endl;
        print();
        cout << '\n';
        cin.get();

        while(generateNext() != false)
        {
            gen++;
            cout << "Generation: " << gen << endl;
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
        write(outName);
        printFile << endl;

        while(generateNext() != false)
        {
            gen++;
            printFile << "Generation: " << gen << endl;
            write(outName);
        }
    }
    else if(out == "4") {}
    else
    {
        cout << "DEFAULT MODE [Press any key to continue...]" << endl;
        cin.get();
        cout << "Generation: " << gen << endl;
        print();
        cout << '\n';
        cin.get();

        while(generateNext() != false)
        {
            gen++;
            cout << "Generation: " << gen << endl;
            print();
            cin.get();
        }
    }
    cout << "Program Exit." << endl;
}
