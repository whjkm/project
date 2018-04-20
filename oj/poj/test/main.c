/*#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n%3==0 && n%5==0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}
*/
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   int m,i;
   scanf("%d",&m);
   if(m<2)
   {
     printf("%d不是素数\n",m);
   }
   for(i=2;i<=sqrt(m);i++)
   {
       if(m%i==0)
        {
            printf("%d不是素数\n",m);
            break;
        }
   }
   if(i>sqrt(m))
   {
     printf("%d是素数\n",m);
   }return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  int i,j;
  for(i=4;i>=1;i--)
  {
      printf("*");
      for(j=1;j<=4-i;j++)
          printf("*");
          printf("\n");

  }
  return 0;
}
