#include <iostream>

using namespace std;

class grid{
private:

  int mode;/*
    0 = Manhattan
    1 = Euclidean
    2 = Heuristic Manhattan
    3 = Heuristic Euclidean(A*)
  */

  int size;
  char** gridSpace;
  int goalPosition[2];
  int initialPosition[2];

public:

  //gameGrid(); if a default grid is ever made, something else is broken
  grid(string file, int setMode); // accepts a text file
  ~grid(); // dynamic memory -> we gotta delete stuff the right way

  // Precondition: x and y are ints within bounds of the grid
  char catPosition(int x, int y);
  // Postcondition: returns char at that position, "Char at position"

  // Precondition: x and y are ints within bounds of the grid
  void fill(int x, int y);
  // Postcondition: Changes char at location to an 'O'

  void print();
  // Postcondition: Prints the grid layout of chars to console

};
