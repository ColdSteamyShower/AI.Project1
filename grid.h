#include <iostream>

using namespace std;

class grid{
private:

  friend class simulation;

  int size;
  char** gridSpace;
  int goalPosition[2];
  int initialPosition[2];

public:

  grid();
  ~grid(); // dynamic memory -> we gotta delete stuff the right way

  void setGrid(string file);
  //Postcondition: Reads the file and moves its information to this grid object

  // Precondition: x and y are ints within bounds of the grid
  char catPosition(int x, int y);
  // Postcondition: returns char at that position, "Char at position". If the position is out of bounds, returns an obstacle

  // Precondition: x and y are ints within bounds of the grid
  void fill(int x, int y);
  // Postcondition: Changes char at location to an 'O'

  void print();
  // Postcondition: Prints the grid layout of chars to console

};
