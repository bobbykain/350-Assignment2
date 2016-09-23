#include <iostream>
#include "Classic.h"

using namespace std;

class Mirror : public Classic
{
public:
  Mirror();
  Mirror(int myrows, int mycols);
  ~Mirror();
  int moses(char** map, int r, int c);
};
