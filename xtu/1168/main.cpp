/*#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int t,n,count;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        for(int i=0;i<14;i++)
        {
            ++count;
            if(n-(int)pow(2,i)==0)
            {
                printf("%d\n",count);
                break;
            }
            n=n-(int)pow(2,i);
            for(int j=0;j<14;j++)
            {
                ++count;
                n=n-(int)pow(3,i);
                if(n-(int)pow(3,i)==0)
                {
                     printf("%d\n",count);
                      break;
                }
            }
        }
    }
    return 0;
}
*/
#include <cstdio>
#include <cstring>
#define min(a,b) a<b?a:b
const int maxn=10005;
const int Max=0x3f3f3f3f;
int dp[maxn][2];
int main()
{
    int t,n,i,j;
    dp[0][0] = dp[0][1] = 0;
    dp[1][0]=dp[1][1]=dp[2][0]=1;
    dp[2][1]=2;
    for(i=3;i<maxn;i++)
    {
        dp[i][0]=dp[i][1]=Max;
        for(j=1;j<=i;j*=2)
            dp[i][0]=min(dp[i][0],dp[i-j][1]+1);
        for(j=1;j<=i;j*=3)
            dp[i][1]=min(dp[i][1],dp[i-j][0]+1);
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n][0]);
    }
    return 0;
}
