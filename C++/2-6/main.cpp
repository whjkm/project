#include <iostream>
#include <stdlib.h>
//#include "Coordinate.h"
#include "Line.h"
using namespace std;

int main()
{
    Line *p =new Line(1,2,3,4);
    p->printInfo();
    delete p;
    p=NULL;
    system("pause");
    return 0;
}
