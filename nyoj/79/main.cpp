#include <cstdio>
#include <cstring>
const int maxn=25;
int a[maxn],dp[maxn],m,Max;
void LICS()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(a[i]<a[j] && dp[i]<dp[j]+1)
              dp[i]=dp[j]+1;
    }
    Max=0;
    for(int i=0;i<m;i++)
        if(Max<dp[i])
        Max=dp[i];
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(int i=0;i<m;i++)
          scanf("%d",&a[i]);
        LICS();
        printf("%d\n",Max);
    }
    return 0;
}
