#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct bag
{
    int x,y,value;
};
bag bag[10];
int dp[1001][1001];
int main()
{
    int t,n,x,y,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&n,&x,&y);
        for(i=0;i<n;i++)
            scanf("%d%d%d",&bag[i].x,&bag[i].y,&bag[i].value);
        for(i=0;i<=x;i++)
            for(j=0;j<=y;j++)
            for(k=0;k<n;k++)
        {
            if(i>=bag[k].x && j>=bag[k].y)
        dp[i][j]=max(dp[i][j],max((dp[i-bag[k].x][j]+dp[bag[k].x][j-bag[k].y]),(dp[i][j-bag[k].y]+dp[i-bag[k].x][bag[k].y]))+bag[k].value);
            if(i>=bag[k].y && j>=bag[k].x)
        dp[i][j]=max(dp[i][j],max((dp[i-bag[k].y][j]+dp[bag[k].y][j-bag[k].x]),(dp[i][j-bag[k].x]+dp[i-bag[k].y][bag[k].x]))+bag[k].value);
        }
        printf("%d\n",dp[x][y]);
    }
    return 0;
}
