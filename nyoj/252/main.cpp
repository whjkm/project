#include <stdio.h>
int main()
{
   int n,m,i;
   int a[40]={3,5};
   scanf("%d",&n);
   while(n--)
   {
       scanf("%d",&m);
       for(i=2;i<m-1;i++)
        a[i]=a[i-1]+a[i-2];
        printf("%d\n",a[m-2]);
   }
    return 0;
}
