#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int cmp(int n,int m)
{
    int a=0,b=0;
    while(n!=0)
    {
        a=a*10+n%10;
        n/=10;
    }
    while(m!=0)
    {
        b=b*10+m%10;
        m/=10;
    }
    return a<b?1:0;
}
int main()
{
   int t,i,j,s[52],a,b;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&a,&b);
       for(i=a,j=0;i<=b;i++)
            s[j++]=i;
      sort(s,s+(b-a)+1,cmp);
      for(i=0;i<j;i++)
        printf("%d ",s[i]);
      printf("\n");
   }
    return 0;
}
