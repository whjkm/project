#include "Soldier.h"

class Infantry:public Soldier
{
    public:
        Infantry(string name="Jack",int age =30);
        virtual ~Infantry();
        void attack();
};


