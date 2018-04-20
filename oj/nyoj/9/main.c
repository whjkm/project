#include <stdio.h>
#define PI 3.1415926
/*int main()
{
   int n,m,i,sum,x;
   scanf("%d",&n);
   while(n--)
   {
       scanf("%d",&m);
       for(i=m,x=1;i>0;i--)
       {
           sum=(x+1)*2;
           x=sum;
       }
       printf("%d\n",sum);
   }
   return 0;
}*/
int main()
{
    int n;
    double x,s;
    scanf("%d",&n);
    while(n--)
    {
       scanf("%lf",&x);
       s=(PI*x*x)/3;
       printf("%0.2f\n",s);
    }
    return 0;
}
