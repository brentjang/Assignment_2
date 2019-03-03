#include <iostream>

using namespace std;

class UserIn
{
private:
    string filename;
    int rows;
    int cols;
    double density;

public:
    UserIn() {};
    ~UserIn() {};
    void checkRows();
    void checkCols();
    void checkDensity();
    void readFile(string filename);
    int getRows();
    int getCols();
    double getDensity();
    string getFileName();
};
