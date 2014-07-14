#include <stdio.h>
#include <string.h>
#define N 100005
int a[N];
long long count[N];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(count,0,sizeof(count));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            count[a[i]]++;
        }
        long long sum=((long long )n*(long long )(n-1))/2;
        for(int i=1;i<=100000;i++)
        {
            if(count[i]==0) continue;
            sum-=((count[i])*(count[i]-1))/2;
            for(int j=i+i;j<=100000;j+=i)
            {
                sum-=count[i]*count[j];
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
