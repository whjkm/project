/*#include <iostream>
#include <stdlib.h>
#include <string>
#include "Teacher.h"
using namespace std;

void test(Teacher t)
{

}
int main()
{
    Teacher t1;
    //test(t1);
    Teacher t2(t1);

    system("pause");
    return 0;
}
*/



#include <iostream>
#include <string>
using namespace std;
/**
 * �����ࣺStudent
 * ���ݳ�Ա��m_strName
 * �޲ι��캯����Student()
 * �вι��캯����Student(string _name)
 * �������캯����Student(const Student& stu)
 * ����������~Student()
 * ���ݳ�Ա������setName(string _name)��getName()
 */
class Student
{
    public:
        Student()
        {
            m_strName = " ";
        }
        Student(string _name)
        {
            m_strName = _name;
        }
        Student(const Student& stu){};
        ~Student(){};
        void setName(string _name);
        string getName();
    private:
      string m_strName;
};

void Student::setName(string _name)
{
    m_strName = _name;
}
string Student::getName()
{
    return m_strName;
}

int main(void)
{
    // ͨ��new��ʽʵ��������*stu
    Student *stu = new Student;
    // ���Ķ�������ݳ�ԱΪ��Ľ������
	stu->setName("Ľ����");
    // ��ӡ��������ݳ�Ա
	cout << stu->getName() <<endl;
    delete stu;
    stu=NULL;
	return 0;
}
