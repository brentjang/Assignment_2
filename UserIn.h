#include <iostream>

using namespace std;

class UserIn
{
private:
    string filename;
    int rows;
    int cols;
    double density;
    int mode;
    int out;

public:
    UserIn() {};
    ~UserIn() {};
    void checkRows();
    void checkCols();
    void checkDensity();
    void checkMode();
    void checkOut();
    void readFile();
    int getRows();
    int getCols();
    double getDensity();
    string getFileName();
    int getMode();
    int getOut();
};
