#include <iostream>
#include <stdlib.h>
#include <string>
#include "Teacher.h"
using namespace std;
int main()
{
    Teacher t1("Merry",12,150);
    //Teacher t2("Merry",15);
    //Teacher t3("James");

    cout << t1.getName() << " " << t1.getAge() << t1.getMax() << endl;
    //cout << t2.getName() << " " << t2.getAge() <<endl;
    //cout << t3.getName() << " " << t3.getAge() <<endl;

    system("pause");
    return 0;
}
