#include <stdio.h>
#define N 100
int main()
{
   int n,a[N]={0},i,t=0;
   while(scanf("%d",&n)&&n!=0)
  {
  for(i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
      if(a[0]>a[i])
      {
          t=a[0];
          a[0]=a[i];
          a[i]=t;
      }
  }
  for(i=0;i<n;i++)
  printf("%d ",a[i]);
  printf("\n");
  }
    return 0;
}
