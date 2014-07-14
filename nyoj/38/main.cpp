#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 0xfffffff
#define MAXN 505
int v,e,ant;
int map[MAXN][MAXN];
int lowcost[MAXN];
int adjvex[MAXN];
void prim()
{
    int i,j,min,k;
    for(i=2;i<=v;i++)
    lowcost[i]=map[0][i];
    for(i=2;i<=v;i++)
    {
        min=INF;
        for(j=1;j<=v;j++)
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        }
        lowcost[k]=0;
        ant+=min;
        for(j=1;i<=v;i++)
        {
            if(lowcost[j]&&map[k][j]<lowcost[j])
            lowcost[j]=map[k][j];
        }
    }
}
int main()
{
    int n,a,b,c,i;
    scanf("%d",&n);
    while(n--)
    {
        ant=0;
        memset(adjvex,0,sizeof(adjvex));
        memset(map,0,sizeof(map));
        memset(lowcost,0,sizeof(lowcost));
        scanf("%d%d",&v,&e);
        for(i=1;i<=e;i++)
            {
                scanf("%d%d%d",&a,&b,&c);
                map[a][b]=map[b][a]=c;
            }
        for(i=1;i<=v;i++)
            scanf("%d",&adjvex[i]);
        sort(adjvex+1,adjvex+v+1);
        prim();
        printf("%d\n",ant+adjvex[1]);
    }
    return 0;
}
