#include <stdio.h>
#include <math.h>
int main()
{
   float a,b,c;
   int t;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%f%f%f",&a,&b,&c);
      if(fabs(a+b-c)<0.0001)
        printf("Yes\n");
      else
        printf("No\n");
   }
    return 0;
}
