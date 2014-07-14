#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=120;
int a[maxn];
int main()
{
   int t,n,x;
   scanf("%d",&t);
   while(t--)
   {
       bool isqueue=true;
       bool isstack=true;
       scanf("%d",&n);
       for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
       for(int i=0;i<n;i++)
       {
        scanf("%d",&x);
        if(x!=a[i])
            isqueue=false;
        if(x!=a[n-i-1])
            isstack=false;
       }
       if(isstack&&isqueue)
          printf("both\n");
       else if(isqueue)
        printf("queue\n");
       else if(isstack)
        printf("stack\n");
       else
        printf("neither\n");
   }
    return 0;
}
