#include <iostream>
#include <fstream>
#include <string>
#include "grid.h"

using namespace std;


grid::grid(string file, int setMode)
{
  mode = setMode;

  string line;
  ifstream infile (file.c_str(), ios::in);
  if(!infile.is_open()){
      cout << "File does not exist" << endl;
      return;
  }
  getline(infile,line); // first line is the width

  // establish grid
  size = stoi(line.c_str());

  initialPosition[0] = 0; initialPosition[1] = 0;
  goalPosition[0] = size-1; goalPosition[1] = size-1;


  gridSpace = new char* [size];
  for(int i=0 ; i<size ; ++i)
  {
    gridSpace[i] = new char [size];
  }

  // fill the grid
  for (int y=0 ; y<size ; ++y){
    getline(infile,line);
    for (int x=0 ; x<size ; ++x){
      if (line[x] == '.' || line[x] == '+' || line[x] == 'i' || line[x] == 'g'){
        gridSpace[x][y] = line[x];
      } else if (line[x] == 'i'){
        initialPosition[0] = x;
        initialPosition[1] = y;
      } else if (line[x] == 'g'){
        goalPosition[0] = x;
        goalPosition[1] = y;
      } else {
        cout << "Aw shit, the text file is wack" << endl;
        return;
      }
    }
  }
}

grid::~grid()
{

}

char grid::catPosition(int x, int y)
{

}

void grid::fill(int x, int y)
{

}

void grid::print()
{
  cout << "Printout for grid.gridSpace" << endl;
  for (int y=0 ; y<size ; ++y){
    for (int x=0 ; x<size ; ++x){
      cout << gridSpace[x][y] << " ";
    }
    cout << endl;
  }
}
