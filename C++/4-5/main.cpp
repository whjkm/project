#include <iostream>
#include "Line.h"
#include <stdlib.h>
using namespace std;

int main()
{
    Line *p = new Line(1,2,3,4);
    p->printInfo();
    delete p;
    p=NULL;

    cout << sizeof(p) <<endl;
    cout << sizeof(Line) <<endl;
    system("pause");
    return 0;
}
