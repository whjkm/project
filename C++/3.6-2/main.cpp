#include <iostream>
#include <stdlib.h>
#include "MigrantWorker.h"
using namespace std;

int main()
{
    MigrantWorker *p = new MigrantWorker("Merry","200","yellow");
    p->Farmer::printColor();
    p->Worker::printColor();
    delete p;
    p = NULL;
    system("pause");
    return 0;
}
