#include <stdio.h>
int add(int k)
{
    int i,sum=0;
    for(i=1;i<=k;i++)
        sum+=i;
    return sum;
}
int main()
{
   int n,k,i,sum,m=1;
   scanf("%d",&n);
   while(n--)
   {
       sum=0;
       scanf("%d",&k);
      for(i=1;i<=k;i++)
        sum+=i*add(i+1);
      printf("%d %d %d\n",m,k,sum);
      m++;
   }
    return 0;
}
