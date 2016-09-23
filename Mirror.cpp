#include <iostream>
#include <fstream>
#include <unistd.h>
#include "General.h"
#include "Mirror.h"

using namespace std;

Mirror::Mirror()
{
  cout << "Mirror object created." << endl;
}

Mirror::Mirror(int myrows, int mycols)
{
  rows = myrows;
  cols = mycols;

  cout << "Mirror object created." << endl;
}

Mirror::~Mirror()
{
  cout << "Mirror object destroyed." << endl;
}

int Mirror::moses(char** map, int r, int c)
{
  int n = 0;
  if (r == 0)
  {
    if (c == 0) // top left
    {
      if (map[0][0] == 'X')
        n += 3;
      if (map[1][0] == 'X')
        n += 2;
      if (map[1][1] == 'X')
        n += 1;
      if (map[0][1] == 'X')
        n += 2;
    }
    if (c == cols - 1) // top right
    {
      if (map[0][cols - 1] == 'X')
        n += 3;
      if (map[1][cols - 1] == 'X')
        n += 2;
      if (map[1][cols - 2] == 'X')
        n += 1;
      if (map[0][cols - 2] == 'X')
        n += 2;
    }
    else // top row
    {
      if (map[0][c] == 'X')
        n++;
      if (map[0][c + 1] == 'X')
        n += 2;
      if (map[0][c - 1] == 'X')
        n += 2;
      for (int below = c - 1; below <= c + 1; ++below)
      {
        if (map[1][below] == 'X')
          n++;
      }
    }
  }
    if (r == rows - 1)
    {
      if (c == 0) // bottom left
      {
        if (map[rows - 1][0] == 'X')
          n += 3;
        if (map[rows - 2][0] == 'X')
          n += 2;
        if (map[rows - 2][1] == 'X')
          n += 1;
        if (map[rows - 1][1] == 'X')
          n += 2;
      }
      if (c == cols - 1) // bottom right
      {
        if (map[rows - 1][cols - 1] == 'X')
          n += 3;
        if (map[rows - 2][cols - 1] == 'X')
          n += 2;
        if (map[rows - 2][cols - 2] == 'X')
          n += 1;
        if (map[rows - 1][cols - 2] == 'X')
          n += 2;
      }
      else // bottom row
      {
        if (map[rows - 1][c] == 'X')
          n++;
        if (map[rows - 1][c + 1] == 'X')
          n += 2;
        if (map[rows - 1][c - 1] == 'X')
          n += 2;
        for (int top = c - 1; top <= c + 1; ++top)
        {
          if (map[rows - 2][top] == 'X')
            n++;
        }
    }
  }
  if ((c == 0) && (r > 0) && (r < rows - 1)) // left side
  {
    if (map[r - 1][0] == 'X')
      n += 2;
    if (map[r + 1][0] == 'X')
      n += 2;
    for (int right = r - 1; right <= r + 1; ++right)
    {
      if (map[right][1] == 'X')
        n++;
    }
  }
  if ((c == cols - 1) && (r > 0) && (r < rows - 1)) // right side
  {
    if (map[r - 1][cols - 1] == 'X')
      n += 2;
    if (map[r + 1][cols - 1] == 'X')
      n += 2;
    for (int right = r - 1; right <= r + 1; ++right)
    {
      if (map[right][cols - 2] == 'X')
        n++;
    }
  }
  if ((c > 0) && (c < cols - 1) && (r > 0) && (r < rows - 1)) // middle of map
  {
    for (int j = 0; j <= r + 1; ++j)
    {
      for (int k = 0; k <= k + 1; ++k)
      {
        if ((j == r) && (k == c))
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
  }
  return n;
}
