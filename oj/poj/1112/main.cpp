#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[10],c[10];
int a[100];
int main()
{
  int t,n,m;
  scanf("%d",&t);
  while(t--)
  {
      int sum=0;
      memset(a,0,sizeof(a));
      scanf("%d",&n);
      for(int i=0;i<n;i++)
       {
           cin>> s;
           if(s[0]=='L')
            a[i]--;
           if(s[0]=='R')
            a[i]++;
            if(s[0]=='S')
           {
               cin>>c;
               cin>>m;
               a[i]=a[m-1];
           }
       }
       for(int i=0;i<n;i++)
           sum+=a[i];
           printf("%d\n",sum);
  }
    return 0;
}
