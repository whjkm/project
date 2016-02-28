#include <iostream>
#include <stdlib.h>
#include "Worker.h"
//#include "Person.h"
using namespace std;

int main()
{
    /*Worker *p =new Worker();
    p->m_strName = "james";
    p->m_iAge=10;
    p->eat();
    p->m_iSalary=10000;
    p->work();
    delete p;
    p=NULL;
*/

    Worker worker;
    /*worker.m_strName="james";
    worker.m_iAge=10;
    worker.eat();
    worker.m_iSalary=10000;*/
    worker.work();


    //Person person;
    //person.m_strName="marry";
    //person.m_iAge=20;
    //person.eat();

    system("pause");
    return 0;
}
