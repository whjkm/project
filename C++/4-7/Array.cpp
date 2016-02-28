#include "Array.h"
#include <iostream>
using namespace std;

Array::Array(int len)
{
    //m_iLen =len;
    this->len=len;
}

Array::~Array()
{

}

int Array::getLen()
{
     //return m_iLen;
     return len;
}

Array* Array::setLen(int len)
{
    //m_iLen=len;
    this->len=len;
    return this;
}

Array *Array::printInfo()
{
    //cout << "len = " << len <<endl;
    cout << this << endl;
    return this;
}
