#include <iostream>
#include <stdlib.h>
#include "Bird.h"
#include "Plane.h"
#include "Flyable.h"
#include <typeinfo>
using namespace std;

void doSomething(Flyable *obj)
{
    cout << typeid(*obj).name() <<endl;
    obj->takeoff();
    if(typeid(*obj) == typeid(Bird))
    {
        Bird *bird = dynamic_cast<Bird * >(obj);
        bird->foraging();
    }
    if(typeid(*obj) == typeid(Plane))
    {
        Plane *plane = dynamic_cast<Plane * >(obj);
        plane->carry();
    }
    obj->land();
}

int main()
{
    Bird b;
    doSomething(&b);

    Plane p;
    doSomething(&p);

    int i =0;
    cout << typeid(i).name() <<endl;

    //Flyable *p = new Bird();
    //cout << typeid(p).name() <<endl;
    //cout << typeid(*p).name() <<endl;

    system("pause");
    return 0;
}
