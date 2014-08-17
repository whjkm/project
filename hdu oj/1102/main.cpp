#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=101;
const int Max=0x3f3f3f3f;
int map[maxn][maxn],low[maxn],visit[maxn];
int n;
int prim()
{
    int i,j,pos,min,mst=0;
    memset(visit,0,sizeof(visit));
    pos=1;
    visit[1]=1;
    for(i=1;i<=n;i++)
        low[i]=map[pos][i];
    for(i=1;i<n;i++)
    {
        min=Max;
        for(j=1;j<=n;j++)
        {
            if(!visit[j] && min>low[j])
            {
                min=low[j];
                pos=j;
            }
        }
        mst+=min;
        if(mst>=Max) break;//说明这个图不连通
        visit[pos]=j;
        for(j=1;j<=n;j++)
        {
            if(!visit[j] && low[j]>map[pos][j])//更新low数组
                low[j]=map[pos][j];
        }
    }
    return mst;
}
int main()
{
    int q,i,j;
    int a,b;
    while(scanf("%d",&n)!=EOF)
    {
        memset(map,Max,sizeof(map));
        for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
            scanf("%d",&map[i][j]);
        scanf("%d",&q);
       while(q--)
       {
           scanf("%d%d",&a,&b);
           map[a][b]=map[b][a]=0;
       }
       printf("%d\n",prim());
    }
    return 0;
}
