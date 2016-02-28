#include "FigherPlane.h"
#include <iostream>
using namespace std;

FigherPlane::FigherPlane(string code):Plane(code)
{

}

void FigherPlane::takeoff()
{
    cout << "FigherPlane::takeoff()" <<endl;
}

void FigherPlane::land()
{
    cout << "FigherPlane::land()" <<endl;
}
