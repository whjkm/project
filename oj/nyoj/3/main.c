#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,i,j;
   scanf("%d",&i);
   while(i)
   {
       scanf("%d",&n);
       for(j=1;j<n;j=j+2)
       printf("%d ",j);
       printf("\n");
       for(j=2;j<=n;j=j+2)
        printf("%d ",j);
        printf("\n");
        i--;
   }
   return 0;
}
