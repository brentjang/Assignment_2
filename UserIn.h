#include <iostream>

using namespace std;

class UserIn
{
private:
    string filename;
    int rows;
    int cols;
    double density;
    int input;
    int mode;
    int out;

public:
    UserIn() {};
    ~UserIn() {};
    void checkRows();
    void checkCols();
    void checkDensity();
    void checkInput();
    void checkMode();
    void checkOut();
    void readFile();
    int getRows();
    int getCols();
    double getDensity();
    string getFileName();
    int getInput();
    int getMode();
    int getOut();
};
