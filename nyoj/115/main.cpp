#include <iostream>
#include <cstring>
#include <cstdio>
const int Max=0x3f3f3f3f;
const int maxn=1001;
int map[maxn][maxn],low[maxn],visit[maxn],city[101],m;
void dijkstra(int start)
{
    int i,j,min,pos;
    memset(visit,0,sizeof(visit));//初始化visit数组
    for(i=1;i<=m;i++)
    {
        low[i]=map[start][i];
    }
    low[start]=0;
    visit[start]=1;
    for(i=1;i<m;i++)
    {
        min=Max;
        pos=0;
        for(j=1;j<=m;j++)
        {
            if(!visit[j] && min>low[j])
            {
                min=low[j];
                pos=j;
            }
        }
        visit[pos]=1;
        for(j=1;j<=m;j++)
        {
            if(low[j]>min+map[pos][j])
                low[j]=min+map[pos][j];
        }
    }
}
int main()
{
    int t,n,p,q;
    int a,b,time,i;
    scanf("%d",&t);
    while(t--)
    {
        memset(map,Max,sizeof(map));
        scanf("%d%d%d%d",&n,&m,&p,&q);
        for(i=0;i<n;i++)
            scanf("%d",&city[i]);
        for(i=0;i<p;i++)
        {
             scanf("%d%d%d",&a,&b,&time);
              if(map[a][b]>time)
              map[a][b]=map[b][a]=time;
        }
        int temp=Max;
        dijkstra(q);
        for(i=0;i<n;i++)
        {
           if(temp>low[city[i]])
              temp=low[city[i]];
        }
        printf("%d\n",temp);
    }
    return 0;
}
