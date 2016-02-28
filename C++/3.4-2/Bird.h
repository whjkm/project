#ifndef BIRD_H
#define BIRD_H
#include "Flyable.h"
#include <string>
using namespace std;

class Bird:public Flyable
{
    public:
       virtual void takeoff();
       virtual void land();
       void foraging();

};

#endif // BIRD_H
