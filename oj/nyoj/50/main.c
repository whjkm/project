#include <stdio.h>
int main()
{
   int n,a[10],i,l,j;
   scanf("%d",&n);
   while(n--)
   {
       j=0;
     for(i=0;i<10;i++)
       scanf("%d",&a[i]);
      scanf("%d",&l);
    for(i=0;i<10;i++)
    {
        if(a[i]<=l+30)
           j++;
    }
    printf("%d\n",j);
   }
    return 0;
}
