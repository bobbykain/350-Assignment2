#include <iostream>

using namespace std;

class General
{
public:
    General();
    ~General();
    char** cBuilder();
    void fBuilder();
    void fOutput();
    void output(char** map);
    void output(char** map, ofstream & outfile);
    int getRows();
    int getCols();
    void setRows(int rows);
    void setCols(int cols);
private:
    int rows;
    int cols;
};
