#include <iostream>
#include <stdlib.h>
#include "Time.h"
#include "Match.h"
using namespace std;

//void printTime(Time &t);

int main()
{
    //Time t(6,34,35);
    //printTime(t);
    Match m(6,30,45);
    m.testTime();

    system("pause");
    return 0;
}

/*void printTime(Time &t)
{
    cout << t.m_iHour << ":" << t.m_iMinute << ":" << t.m_iSecond <<endl;
}
*/
