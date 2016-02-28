#include <iostream>
#include <stdlib.h>
#include "Line.h"
using namespace std;

int main()
{
    const Line Line(1,2,3,4);
    Line.printInfo();

    system("pause");
    return 0;
}
