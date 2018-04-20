//poj3750小孩报数问题，编译错误。。。

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
   string name[65];//存储名字
   int n,w,s,index[65];
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       cin >> name[i];
       index[i]=i; //存储每个小孩的位置的序号
   }
   scanf("%d%d",&w,&s);
   w=(w+n-1)%n;//最初w的位置
   do
   {
       w=(w+s-1)%n;
      cout<< name[index[w]] <<endl;
       for(int i=w;i<n-1;i++)//把后面的元素向前移动一位
        index[i]=index[i+1];
   }
   while(--n);
   return 0;
}
