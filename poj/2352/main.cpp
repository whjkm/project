#include <stdio.h>
#define N 32002
int levels[N];
int c[N];
int lowbit(int x)
{
    return x&(-x);
}
int sum(int x)
{
    int temp=0;
    while(x>0)
    {
        temp+=c[x];
        x-=lowbit(x);
    }
    return temp;
}
void update(int x)
{
    while(x<=N)
    {
        c[x]++;
        x+=lowbit(x);
    }
}
int main()
{
   int n,x,y;
   scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
      scanf("%d%d",&x,&y);
      levels[sum(x+1)]++;
      update(x+1);
  }
  for(int i=0;i<n;i++)
    printf("%d\n",levels[i]);
    return 0;
}
