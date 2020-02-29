#include <iostream>
#include "grid.h"

using namespace std;

int main()
{
    grid testGrid("map.txt", 0);
    testGrid.print();
}
