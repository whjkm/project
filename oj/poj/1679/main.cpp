/*#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn=100+10;
using namespace std;
struct node
{
    int v,u,cost;
};
node map[maxn*maxn];
int father[maxn];
int n,m;
bool cmp(node x,node y)
{
    return x.cost<y.cost;
}
void Init()
{
    for(int i=1;i<=n;i++)
        father[i]=i;
}
int  find_set(int x)
{
    if(father[x]==x)
        return x;
    else
        return father[x]=find_set(father[x]);
}
bool union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if(x!=y)
    {
        father[y]=x;
        return true;
    }
    else
    {
        return false;
    }
}
int kruskal()
{

}
int main()
{
    int t,x,y,w,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
        {
         scanf("%d%d%d",&map[i].u,&map[i].v,&map[i].cost);
        }
    }
    return 0;
}
*/


#include <cstdio>
#include <cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int maxn=100+5;
const int INF=0x3fffffff;
int map[maxn][maxn],low[maxn];
int path[maxn][maxn],pre[maxn];
int visit[maxn],used[maxn][maxn];
int n,m;
int prim()
{
   int i,j,pos,mst=0;
   memset(visit,0,sizeof(visit));
   memset(path,0,sizeof(path));
   memset(used,0,sizeof(used));
   visit[1]=1;
   pos=1;
   for(i=1;i<=n;i++)
    {
        low[i]=map[1][i];
        pre[i]=1;
    }
   for(i=1;i<n;i++)
   {
      int mins=INF;
      for(j=1;j<=n;j++)
      {
          if(!visit[j]&&low[j]<mins)
              {
                  mins=low[j];
                  pos=j;
              }
      }
      used[pos][pre[pos]]=used[pre[pos]][pos]=1;
      mst+=map[pos][pre[pos]];
      visit[pos]=1;
      for(j=1;j<=n;j++)
      {
           if(visit[j]&&j!=pos)
               path[pos][j]=path[j][pos]=max(path[j][pre[pos]],low[pos]);
           if(!visit[j]&&low[j]>map[pos][j])
           {
               low[j]=map[pos][j];
               pre[j]=pos;
           }
      }
   }
   return mst;
}

int main()
{
    int t,x,y,w,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            map[i][j]=INF;
        for(i=1;i<=m;i++)
        {
         scanf("%d%d%d",&x,&y,&w);
         map[x][y]=map[y][x]=w;
        }
        int mst;
        int res=INF;
        mst=prim();
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
        {
            if(i!=j&& !used[i][j])
                 res=min(res,mst+map[i][j]-path[i][j]);
        }
        if(res==mst)
            puts("Not Unique!");
        else
            printf("%d\n",mst);
    }
    return 0;
}
