#include <iostream>
#include "General.h"
#include "Mirror.h"

using namespace std;

int main(int argc, char** argv)
{
  General g1;

  cout << "How do you want to input to the program? (enter console or file): ";
  string answer;
  cin >> answer;

  char** map;
  if (answer == "console")
  {
    map = g1.cBuilder();
  }
  else
  {
    cout << "Type the name of your input file: ";
    string file;
    cin >> file;
    map = g1.fBuilder(file);
  }

  Mirror c1 (g1.getRows(), g1.getCols());

  c1.god(map);

  return 0;
}
