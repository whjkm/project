//poj3750С���������⣬������󡣡���

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
   string name[65];//�洢����
   int n,w,s,index[65];
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       cin >> name[i];
       index[i]=i; //�洢ÿ��С����λ�õ����
   }
   scanf("%d%d",&w,&s);
   w=(w+n-1)%n;//���w��λ��
   do
   {
       w=(w+s-1)%n;
      cout<< name[index[w]] <<endl;
       for(int i=w;i<n-1;i++)//�Ѻ����Ԫ����ǰ�ƶ�һλ
        index[i]=index[i+1];
   }
   while(--n);
   return 0;
}
