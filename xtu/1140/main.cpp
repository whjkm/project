#include <stdio.h>
#define N 1000002
long long prime[N]={0};
long long count[N]={0};
int main()
{
    long long n,len=0;
    for(int i=2;i<=N/2;i++)
      {
        for(int j=i+i;j<=N;j+=i)
          {
           if(j%2==1)
              prime[j]=1;
          }
      }
      for(int i=9;i<=N;i++)
      {
          if(prime[i])
            len++;
          count[i+4]=len;
      }
    while(scanf("%I64d",&n)!=EOF)
    {
        long long sum=0;
        for(int i=13;i<=n;i=i+2)
           sum+=count[i];
        printf("%I64d\n",sum);
    }
    return 0;
}
