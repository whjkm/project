#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect(double width,double height)
{
    cout << "Rect()" <<endl;
    m_dWidth = width;
    m_dHeight = height;
}

Rect::~Rect()
{
     cout << "~Rect()" <<endl;
}

double Rect::calcArea()
{
    cout << "Rect::calcArea()" <<endl;
    return m_dWidth * m_dHeight;
}
