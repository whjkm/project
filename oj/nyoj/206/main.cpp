#include <stdio.h>
int main()
{
   int a,b,i,j;
   long long sum;
   while(scanf("%d%d",&a,&b)!=EOF)
   {
       sum=0;
     for(i=a;i>0;i--)
        for(j=b;j>0;j--)
        sum+=i*j;
     printf("%lld\n",sum);
   }
    return 0;
}

/*#include<stdio.h>
 int main()
 {
 long long a, b;
 while(scanf("%lld%lld", &a, &b) != EOF)
 {
 printf("%lld\n", (a+1)*(b+1)*a*b/4);
 }
 return 0;
 }
*/
