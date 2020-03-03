#include <iostream>
#include "path.h"
#include <list>
#include <utility>

using namespace std;

path::path(int x, int y)
{
  position[0] = x;
  position[1] = y;

  moves = 0;

  history.push_back(make_pair(x, y)); // the initial location
}



path::path(int x, int y, const path &p)
{
  position[0] = x;
  position[1] = y;

  moves = p.moves+1;

  history = p.history;
  history.push_back(make_pair(x,y));
}

bool path::overlap(int x, int y)
{
  pair<int,int> temp = make_pair(x,y);
  for(pair<int,int> p : history)
  {
    if(temp == p)
      return false;
  }
  return true;
}
