#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker()
{
   cout << "Worker()" <<endl;
}

Worker::~Worker()
{
   cout << "~Worker()" <<endl;
}

void Worker::work()
{
    m_strName="Jim";
    m_iAge=20;
    cout << "work()" <<endl;
}
