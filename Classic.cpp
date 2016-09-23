#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Classic.h"
#include "General.h"

using namespace std;

Classic::Classic()
{
  cout << "Classic object created." << endl;
}

Classic::Classic(int myrows, int mycols)
{
  rows = myrows;
  cols = mycols;

  cout << "Classic object created." << endl;
}

Classic::~Classic()
{
  cout << "Classic obhect destroyed." << endl;
}

int Classic::moses(char** map, int r, int c)
{
	int n = 0;
	for (int j = r - 1; j <= r + 1; ++j)
  {
		for (int k = c - 1; k <= c + 1; ++k)
    {
			if(j >= rows)
      {
				continue;
			}
			if(k >= cols)
      {
				continue;
			}
			if(j < 0)
      {
				continue;
			}
			if(k < 0)
      {
				continue;
			}
			if((j == r) && (k == c))
      {
				continue;
			}
			else
      {
				if (map[j][k] == 'X')
        {
					n++;
				}
			}
		}
	}
	return n;
}

char Classic::prophet(int n)
{
	if(n <= 1)
  {
		return '-';
	}
	else if(n == 2)
  {
		return '+';
	}
	else if(n == 3)
  {
		return 'X';
	}
	else
  {
		return '-';
	}
}

void Classic::god(char** map)
{
  General g;
  g.setCols(cols);
  g.setRows(rows);

  int count;
  int n;
  char t;

  cout << "Would you like to output to a file or to the console? (type console if you want to output to console, otherwise type the name of your output file): ";
  string answer;
  cin >> answer;
  ofstream outfile(answer);

  string forEnter;
  cout << "Would you like to delay generations by pressing enter, a set delay, or none? (enter enter, delay, or none): ";
  string time;
  cin >> time;


  char** newmap = new char*[rows];
  for (int i = 0; i < rows; ++i)
  {
    newmap[i] = new char[cols];
  }

  for (int r = 0; r < rows; ++r)
  {
    for (int c = 0; c < cols; ++c)
    {
      newmap[r][c] = '-';
    }
  }

  while (true)
  {
    count = 0;

    for (int r = 0; r < rows; ++r)
    {
      for (int c = 0; c < cols; ++c)
      {
        n = moses(map, r, c);
        t = prophet(n);

        if (t == '+')
        {
          newmap[r][c] = map[r][c];
        }
        else
        {
          newmap[r][c] = t;
        }
      }
    }

    for (int r = 0; r < rows; ++r)
    {
			for (int c = 0; c < cols; ++c)
      {
				if (newmap[r][c] != map[r][c])
        {
					count++;
				}
			}
		}

    if (count == 0)
    {
      break;
    }

    for (int r = 0; r < rows; ++r)
    {
			for (int c = 0; c < cols; ++c)
      {
				map[r][c] = newmap[r][c];
			}
		}

    if (answer == "console")
    {
      g.output(map);
    }
    else
    {
      g.output(map, outfile);
    }

    if (time == "delay")
    {
      sleep(1);
    }
    else if (time == "enter")
    {
      cin.get();
    }
  }
  outfile.close();
}
