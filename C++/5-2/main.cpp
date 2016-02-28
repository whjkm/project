#include <iostream>
#include <stdlib.h>
#include <string>
#include "Teacher.h"
using namespace std;
int main()
{
    Teacher t;
    t.setName("kongzi");
    t.setGender("man");
    t.setAge(30);
    cout<< t.getName() << " "<< t.getGender() <<" "<<t.getAge();
    t.teach();
    system("pause");
    return 0;
}
