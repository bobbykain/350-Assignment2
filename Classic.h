#include <iostream>

using namespace std;

class Classic
{
public:
  Classic();
  Classic(int myrows, int mycols);
	~Classic();
	void god(char** map);//iterates through pointer
	char prophet(int n);//decides on life or death
	int moses(char** map, int r, int c); //counts amount of neighbors
protected:
  int rows;
  int cols;
};
