/*#include<stdio.h>
int main()
{
int T;
scanf("%d",&T);
while(T--)
{
int a,b,d;
char c;
scanf("%x%c%x",&a,&c,&b);
if(c=='+') d=a+b;
else d=a-b;
if(d>=0)
printf("%o\n",d);
else printf("-%o\n",-d);
}
return 0;
}
*/

/*#include <stdio.h>
#include <math.h>
char a1[20];
int main()
{
int r,a,b,t;
char sign;
scanf("%d",&t);
while(t--)
{
scanf("%x%c%x",&a,&sign,&b);
r=sign=='+'?a+b:a-b;
printf("%o\n",r);
}
return 0;

}
*/
#include<stdio.h>
#include <math.h>
char a1[20];
int main()
{
    int t,a,b,sum;
    char sign;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%x%c%x",&a,&sign,&b);
      sum=sign=='+'?a+b:a-b;
      printf("%o\n",sum);
    }
    return 0;
}
