#include <cstdio>
#include <cstring>
const int maxn=10001;
char s[maxn];
int dp[maxn],Max;
void LICS()
{
    int len;
    memset(dp,0,sizeof(dp));
    len=strlen(s);
    for(int i=0;i<len;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(s[i]>s[j] && dp[i]<1+dp[j])
                dp[i]=1+dp[j];
        }
    }
    Max=0;
    for(int i=0;i<len;i++)
        if(Max<dp[i])
          Max=dp[i];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        LICS();
        printf("%d\n",Max);
    }
    return 0;
}
