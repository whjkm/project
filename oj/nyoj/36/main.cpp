#include <cstdio>
#include <cstring>
#define max(a, b) a > b ? a : b
using namespace std;
const int maxn=1001;
int dp[maxn][maxn];
char s1[maxn],s2[maxn];
int main()
{
    int n;
    int len1,len2;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%s%s",s1,s2);
        len1=strlen(s1);
        len2=strlen(s2);
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
