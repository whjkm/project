#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a,n,sum,i,t,j;
   scanf("%d",&a);
   while(a--)
   {
       sum=0;
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       {
         for(j=1,t=1;j<=i;j+=2)
       {
          t=t*j;
       }
         sum+=t;
       }
       printf("%d\n",sum);
   }
    return 0;
}

/*include<stdio.h>
 int main()
 {
 int a,b,c,d,e;
 scanf("%d",&a);
 while(a--)
 {
 int f=0;
 scanf("%d",&b);
 for(c=1;c<=b;c++)
 {
 for(d=1,e=1;d<=c;d+=2)
 {
 e=e*d;
 }
 f=f+e;
 }
 printf("%d\n",f);
 }
 return 0;
 }
 */
