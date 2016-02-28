#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker(string code)
{
    m_strCode = code ;
    cout << "Work()" <<endl;
}

Worker::~Worker()
{
    cout << "~Work()" <<endl;
}

void Worker::carry()
{
    cout << m_strCode << endl;
    cout << "Worker::carry()" <<endl;
}
