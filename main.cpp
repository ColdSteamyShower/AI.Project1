#include <iostream>
#include "simulation.h"

using namespace std;

int main(int argc, char *argv[])
{
    simulation testMan(argv[1],0);
    testMan.run();
    cout << "Manhattan Function:" << endl;
    testMan.print();

    simulation testEuc(argv[1],1);
    testEuc.run();
    cout << "Euclidean Function:" << endl;
    testEuc.print();

    simulation testHeurMan(argv[1],2);
    testHeurMan.run();
    cout << "Heuristic Manhattan Function:" << endl;
    testHeurMan.print();

    simulation testHeurEuc(argv[1],3);
    testHeurEuc.run();
    cout << "Heuristic Euclidean Function:" << endl;
    testHeurEuc.print();

}
