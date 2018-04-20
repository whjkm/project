#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=101;
int a[maxn][maxn];
int *dp;
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
        scanf("%d",&a[i][j]);
        dp=a[n];
    for(i=n-1;i>=0;i--)
        for(j=1;j<=i;j++)
        dp[j]=max(dp[j],dp[j+1])+a[i][j];
    printf("%d\n",dp[1]);
    return 0;
}
