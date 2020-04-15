#include <iostream>
#include "map.h"
#include "C3PO.h"
using namespace std;

int main()
{
    map M;
    M.generateFinish();
    //M.generateItems();
    //M.generateTraps();
    cout << M;
    return 0;
}
