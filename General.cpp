#include <iostream>
#include <fstream>
#include "General.h"

using namespace std;

General::General()
{
  cout << "General object created." << endl;
}

General::~General()
{
  cout << "General object destroyed." << endl;
}

void General::setRows(int myrows)
{
  rows = myrows;
}

void General::setCols(int mycols)
{
  cols = mycols;
}

int General::getRows()
{
  return rows;
}

int General::getCols()
{
  return cols;
}

char** General::cBuilder()
{
  cout << "Please enter the number of rows in your array: ";
  cin >> rows;
  cout << "Please enter the number of columns in your array: ";
  cin >> cols;
  cout << "Please enter the population density for your array: ";
  double seed;
  cin >> seed;
  cout << "Thanks." << endl;

  char **map = new char*[rows];
  for (int i = 0; i < rows; ++i)
  {
    map[i] = new char[cols];
  }

  for (int r = 0; r < rows; ++r)
  {
    for (int c = 0; c < cols; ++c)
    {
      double roll = rand();
			roll = roll / RAND_MAX;
			if (roll < seed)
      {
				map[r][c] = 'X';
      }
      else
      {
        map[r][c] = '-';
      }
    }
  }
  return map;
}

void General::output(char** map)
{
  for (int r = 0; r < rows; ++r)
  {
    for (int c = 0; c < cols; ++c)
    {
      cout << map[r][c];
    }
    cout << "\n";
  }
  cout << "" << endl;
}

void General::output(char** map, ofstream & out)
{
  out << "success!";
  for (int r = 0; r < rows; ++r)
  {
    for (int c = 0; c < cols; ++c)
    {
      out << map[r][c];
    }
    out << "\n";
  }
  out << "" << endl;
}
