#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <list>
#include "path.h"
#include "grid.h"
#include <math.h>

using namespace std;

class simulation{
private:

  int mode;/*
    0 = Manhattan
    1 = Euclidean
    2 = Heuristic Manhattan
    3 = Heuristic Euclidean(A*)
  */

  int cost;

  grid simGrid;
  list<path> stateSpaces;

public:

  // constructor
  simulation(string file, int m);

  // Precondition: Simulation object is properly set up
  void run();
  // Postcondition: Simulation is run and the result is printed to console

  // Precondition: path p is valid
  double scoreFunction(path p);
  // Postcondition: Based on the mode of the simulation, an int representing the score of the path will be returned


  // Successor Function!
  // Precondition: stateSpaces has at least 1 path object
  bool expandPaths();
  // Postcondition: Removes the space with the best score and adds avaliable spaces adjacent to it into the list

  void print();

};
