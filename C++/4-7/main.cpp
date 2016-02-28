#include <iostream>
#include "Array.h"
#include <stdlib.h>
using namespace std;

int main()
{
    Array arr1(10);
    arr1.printInfo();
    cout << &arr1 <<endl;
    //arr1.printInfo()->setLen(5)->printInfo();
    //cout <<"len =  " << arr1.getLen() <<endl;
    system("pause");
    return 0;
}
