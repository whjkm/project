#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(int hour,int min,int sec)
{
    m_iHour = hour;
    m_iMinute = min;
    m_iSecond = sec;
}

void Time::printTime()
{
    cout << m_iHour << ":" << m_iMinute << ":" << m_iSecond <<endl;
}


