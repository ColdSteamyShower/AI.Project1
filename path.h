#include <iostream>
#include <list>

using namespace std;

class path{
private:

  friend class simulation;

  int position[2];              // where the path currently ends
  int moves;                    // how many moves does this path have?
  list<pair<int,int>> history;  // where this path has been?

public:

  // The initial position
  path(int x, int y);

  // "Copy constructor" but not really
  path(int x, int y, const path &p);

  // Precondition: parameters are positions somewhere on the grid
  bool overlap(int x, int y);
  // Postcondition: Returns false only if (x,y) is in the history

};
