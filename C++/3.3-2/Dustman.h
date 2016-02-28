#ifndef DUSTMAN_H
#define DUSTMAN_H
#include "Worker.h"

class Dustman:public Worker
{
    public:
        Dustman(string name , int age);
        //virtual ~Dustman();
        virtual void work();
    protected:
    private:
};

#endif // DUSTMAN_H
