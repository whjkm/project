#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include "Coordinate.h"

class Circle:public Shape
{
    public:
        Circle(double r);
        virtual ~Circle();
        double calcArea();
    protected:
        double m_dR;
        Coordinate *m_pCenter;
    private:
};

#endif // CIRCLE_H
