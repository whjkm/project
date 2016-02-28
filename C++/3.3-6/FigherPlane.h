#ifndef FIGHERPLANE_H
#define FIGHERPLANE_H
#include "Plane.h"
#include <string>
using namespace std;

class FigherPlane:public Plane,public Flyable
{
    public:
        FigherPlane(string code);
        //virtual ~FigherPlane();
        virtual void takeoff();
        virtual void land();
    protected:
    private:
};

#endif // FIGHERPLANE_H
