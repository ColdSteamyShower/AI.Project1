#include <iostream>
#include <list>
#include "simulation.h"

using namespace std;

simulation::simulation(string file, int m)
{
  simGrid.setGrid(file);
  cost = 0;
  mode = m;
  stateSpaces.push_back(path(simGrid.initialPosition[0],simGrid.initialPosition[1]));
  cout << "initial state space created at ";
  for(path p : stateSpaces){
    cout << p.position[0] << "," << p.position[1] << endl;
  }
}

void simulation::run()
{
  do{
    if(expandPaths())
      break;
  }while(true);
}

double simulation::scoreFunction(path p)
{
  double rise = p.position[1] - simGrid.goalPosition[1];
  if (rise < 0)
    rise *= -1;
  double run = p.position[0] - simGrid.goalPosition[0];
  if (run < 0)
    run *= -1;

  switch(mode){
    case 0: // manhattan
            return (rise+run);
    case 1: // euclidean
            return (sqrt(pow(rise,2)+pow(run,2)));
    case 2: // heuristic manhattan
            return p.moves + (rise+run);
    case 3: // heuristic euclidean
            return p.moves + (sqrt(pow(rise,2)+pow(run,2)));
  }
}

bool simulation::expandPaths()
{
  ++cost;
  //sleep(1);
  // find the best path avaliable
  path bestNextCase = stateSpaces.front();
  int index = 0;
  int iteration = 0;
  for(path p : stateSpaces){
    if(scoreFunction(p) < scoreFunction(bestNextCase)){
      bestNextCase = p;
      index = iteration;
    } else {
    }
    ++iteration;
  }
  // check if that path is at the goal
  if (bestNextCase.position[0] == simGrid.goalPosition[0] && bestNextCase.position[1] == simGrid.goalPosition[1]){
    for(pair<int,int> p : bestNextCase.history){ // if it is, fill in all the points along that path
      if(simGrid.gridSpace[p.first][p.second] == '.')
        simGrid.fill(p.first,p.second);
    }
      return true; // we are at the goal, get out of here

  }

  // create up to 4 "new" positions based on this one

  int bestCasePosition[2] = {bestNextCase.position[0], bestNextCase.position[0]};
  int up[2] = {bestNextCase.position[0], bestNextCase.position[1]+1};
  int down[2] = {bestNextCase.position[0], bestNextCase.position[1]-1};
  int left[2] = {bestNextCase.position[0]-1, bestNextCase.position[1]};
  int right[2] = {bestNextCase.position[0]+1, bestNextCase.position[1]};


      // we need to check if the source case has been there already, if there is an obstruction
  if(bestNextCase.overlap(up[0],up[1]) && simGrid.catPosition(up[0],up[1]) != '+'){
    path toInsert(up[0],up[1],bestNextCase);
    stateSpaces.push_back(toInsert);
  }

  if(bestNextCase.overlap(down[0],down[1]) && simGrid.catPosition(down[0],down[1]) != '+'){
    path toInsert(down[0],down[1],bestNextCase);
    stateSpaces.push_back(toInsert);
  }

  if(bestNextCase.overlap(left[0],left[1]) && simGrid.catPosition(left[0],left[1]) != '+'){
    path toInsert(left[0],left[1],bestNextCase);
    stateSpaces.push_back(toInsert);
  }

  if(bestNextCase.overlap(right[0],right[1]) && simGrid.catPosition(right[0],right[1]) != '+'){
    path toInsert(right[0],right[1],bestNextCase);
    stateSpaces.push_back(toInsert);
  }

  //stateSpaces.erase(stateSpaces.begin()+index);
  list<path>::iterator it=stateSpaces.begin();
  advance(it,index);
  stateSpaces.erase(it);

  return false;
}

void simulation::print(){
  simGrid.print();
  cout << "Runtime cost: " << cost << " search cycles" << endl;
}
