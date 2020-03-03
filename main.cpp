#include <iostream>
#include "simulation.h"

using namespace std;

int main(int argc, char *argv[])
{
    simulation testMan(argv[1],0);
    testMan.run();
    testMan.print();

    simulation testEuc(argv[1],1);
    testEuc.run();
    testEuc.print();

    simulation testHeurMan(argv[1],2);
    testHeurMan.run();
    testHeurMan.print();

    simulation testHeurEuc(argv[1],3);
    testHeurEuc.run();
    testHeurEuc.print();

}
