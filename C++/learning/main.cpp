/*#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int x=0;
    cout <<  "请输入一个整数：" << endl;
    cin >> x;
    cout << oct << x << endl;
    cout << dec << x << endl;
    cout << hex << x << endl;

    cout << "请输入一个布尔值（0,1）：" << endl;
    bool y=false;
    cin >>y;
    cout << boolalpha << y << endl;


    return 0;
}
*/
/*#include <stdlib.h>
#include <iostream>
using namespace std;

namespace A
{
    int x=1;
    void fun()
    {
        std::cout << "A" << std::endl;
    }
}

namespace B
{
    int x=2;
    void fun()
    {
        std::cout << "B" << std::endl;
    }
    void fun2()
    {
        std::cout << "2B" << std::endl;
    }
}
using namespace B;
int main()
{
    std::cout << A::x << std::endl;
    B::fun();
    fun2();
    system("pause");
    return 0;
}
*/

/*#include <stdlib.h>
#include <iostream>
using namespace std;

namespace CompA
{
    int getMaxOrMin(int *arr,int count,bool isMax)
{
    int temp = arr[0];
    for(int i=1; i<count; i++)
    {
        if(isMax)
        {
            if(temp < arr[i])
            {
                temp =arr[i];
            }
        }
        else
        {
            if(temp > arr[i])
            {
                temp =arr[i];
            }
        }
    }
    return temp;
}
}

int main()
{
    int arr1[4]={3,5,1,7};
    bool isMax=false;
    cin >> isMax;
    cout<< CompA::getMaxOrMin(arr1,4,isMax) << endl;
    system("pause");
    return 0;
}
*/

//引用
/*#include <iostream>
#include <stdlib.h>
using namespace std;

void fun(int &a,int &b);

int main()
{
    int x=10;
    int y=20;
    cout << x << "," << y <<endl;
    fun(x,y);
    cout << x << "," << y <<endl;
    system("pause");
    return 0;
}

void fun(int &a,int &b)
{
    int c=0;
    c=a;
    a=b;
    b=c;
}
*/

//const代码演示
/*#include <iostream>
#include <stdlib.h>
using namespace std;

void fun(const int &a,const int &b);
int main()
{
    int x=3;
    int y=5;
    fun(x,y);
    cout << x << "," << y <<endl;
    system("pause");
    return 0;
}

void fun(const int &a,const int &b)
{
    a=10;
    b=20;
}
*/

//函数特性演示

/*#include <stdlib.h>
#include <iostream>
using namespace std;

inline void fun(int i=30,int j=20,int k=10);
inline void fun(double i,double j);

int main()
{
    fun(1.1,2.2);
    fun(1,2);
    system("pause");
    return 0;
}

void fun(int i,int j,int k)
{
    cout << i <<","<< j << ","<< k <<endl;
}

void fun(double i,double j)
{
    cout << i <<","<< j <<endl;
}
*/

//内存管理

/*#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int *p=new int[1000];
    if(NULL == p)
    {
    system("pause");
    return 0;
    }
    p[0]=10;
    p[1]=20;
    cout <<p[0] << "," << p[1] <<endl;
    delete [] p;
    p=NULL;
    system("pause");
    return 0;
}
*/

//类对象的定义

/*#include <stdlib.h>
#include <iostream>
using namespace std;

class Coordinate
{
public:
    int x;
    int y;
    void printx()
    {
        cout << x << endl;
    }
    void printy()
    {
        cout << y << endl;
    }
};
int main()
{
    Coordinate coor;
    coor.x = 10;
    coor.y = 20;
    coor.printx();
    coor.printy();


    Coordinate *p = new Coordinate();
    if(NULL == p)
    {
        //failed
        return 0;
    }
    p->x=100;
    p->y=200;
    p->printx();
    p->printy();
    delete p;
    p==NULL;

    system("pause");
    return 0;
}
*/

//string类型
/*#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "please input your name:";
    getline(cin,name);
    if(name.empty())
    {
        cout<< "input is null" <<endl;
        system("pause");
        return 0;
    }
    if(name == "imooc")
    {
        cout<< "your are a administrator" << endl;
    }
    cout << "hello" + name <<endl;
    cout << "your name length:" << name.size() <<endl;
    cout << "your name first letter is :" << name[0] <<endl;
    system("pause");
    return 0;
}
*/

//数据的封装

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    void setName(string _name)
    {
        m_strName=_name;
    }
    string getName()
    {
        return m_strName;
    }
    void setGender(string _gender)
    {
        m_strGender=_gender;
    }
    string getGender()
    {
        return m_strGender;
    }
    int getScore()
    {
        return m_iScore;
    }
    void initScore()
    {
        m_iScore=0;
    }
    void study(int _score)
    {
        m_iScore+=_score;
    }
private:
    string m_strName;
    string m_strGender;
    int m_iScore;
};

int main()
{
    Student stu;
    stu.initScore();
    stu.setName("zhangsan");
    stu.setGender("女");
    stu.study(5);
    stu.study(3);

    cout << stu.getName() << " " << stu.getGender() << " " << stu.getScore() << endl;
    system("pause");
    return 0;
}
