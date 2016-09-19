#include <iostream>
#include "General.h"
#include "Classic.h"

using namespace std;

int main(int argc, char** argv)
{
  General g1;

  char** map = g1.cBuilder();

  Classic c1 (g1.getRows(), g1.getCols());

  c1.god(map);

  return 0;
}
