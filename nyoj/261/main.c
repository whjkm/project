#include <stdio.h>
int main()
{
   int n,i,j,a[3][3];
   scanf("%d",&n);
   while(n--)
   {
       for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
        for(i=0;i<3;i++)
           {for(j=0;j<3;j++)
             printf("%d ",a[j][i]);
          printf("\n");
           }
   }
    return 0;
}
