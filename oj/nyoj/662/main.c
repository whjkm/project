#include <stdio.h>
#include <stdlib.h>
int main()
{
   int n,temp,sum;
   while(scanf("%d",&n)&&n!=0)
   {
       sum=0,temp=0;
       while(n>=3)
       {
           temp=n/3;
           sum+=temp;
           n=n/3+n%3;
       }
       if(n==2)
        sum++;
         printf("%d\n",sum);
   }
    return 0;
}
