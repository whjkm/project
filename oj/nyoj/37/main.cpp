#include <cstdio>
#include <cstring>
#define max(a,b) a>b?a:b
const int maxn=1001;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int main()
{
    int n,i,j,len;
    scanf("%d",&n);
    while(n--)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        scanf("%s",a);
        len=strlen(a);
        for(i=len-1,j=0;i>=0;i--)
            b[j++]=a[i];
        for(i=1;i<=len;i++)
        {
            for(j=1;j<=len;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",len-dp[len][len]);
    }
}
