#include <cstdio>
#include <cstring>
#define max(a,b) a>b?a:b
int map[25][25],dp[25][25];
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scanf("%d",&map[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        //dp[i][j]=max(dp[i-1][j]+map[i][j],dp[i][j-1]+map[i][j]);
        map[i][j]+=max(map[i][j-1],map[i-1][j]);
    printf("%d\n",map[n][m]);
}
