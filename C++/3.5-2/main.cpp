#include <iostream>
#include <stdlib.h>
#include "IndexException.h"
using namespace std;

void test()
{
   throw IndexException();
}

int main()
{
   try
   {
       test();
   }
   catch(...)
   {
       //e.printException();
       cout << "exception" <<endl;
   }

    system("pause");
    return 0;
}
