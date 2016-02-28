#include "Soldier.h"
#include <iostream>
using namespace std;

Soldier::Soldier()
{
    //ctor
}

void Soldier::work()
{
    m_strName = "Jim";
    m_iAge = 20;
    cout << m_strName <<endl;
    cout << m_iAge <<endl;
    cout << "Soldier::work()" <<endl;
}
