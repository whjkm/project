/*#include <cstdio>
#include <cstring>
const int Max=0x3f3f3f3f;
const int maxn=100+10;
int map[maxn][maxn],low[maxn],visit[maxn];
int n;
int prim()
{
   int pos,i,j,min,sum=0;
   memset(visit,0,sizeof(visit));
   visit[1]=1;
   pos=1;
   for(i=1;i<=n;i++)
      low[i]=map[pos][i];
   for(i=1;i<n;i++)
   {
       min=Max;
       for(j=1;j<=n;j++)
       {
           if(visit[j]==0&&low[j]!=0&&low[j]<min)
           {
               min=low[j];
               pos=j;
           }
       }
       sum+=min;
       visit[pos]=1;
       for(j=1;j<=n;j++)
       {
           if(visit[j]==0&&low[j]>map[pos][j])
              low[j]=map[pos][j];
       }
   }
   return sum;
}
int main()
{
    int sum,i,j;
    while(scanf("%d",&n)!=EOF)
    {
     sum=0;
     memset(map,Max,sizeof(map));
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           scanf("%d",&map[i][j]);
      sum=prim();
      printf("%d\n",sum);
    }
    return 0;
}
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    int u,v,cost;
};
node map[100002];
int father[102];
int n,k;
bool cmp(node a,node b)
{
    return a.cost<b.cost;
}
void Init()
{
    for(int i=1;i<=n;i++)
        father[i]=i;
}
int find_set(int x)
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
   int i,mst_edge=0,sum=0;
   Init();
   sort(map,map+k,cmp);
   for(i=1;i<=k;i++)
   {
       if(union_set(map[i].u,map[i].v))
          {
              sum+=map[i].cost;
              mst_edge++;
          }
   }
   if(mst_edge==n-1)
     return sum;
  return mst_edge;
}
int main()
{
    int i,j,w;
    while(scanf("%d",&n)!=EOF)
    {
      k=0;
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&w);
            if(i!=j)
            {
                map[k].u=i;
                map[k].v=j;
                map[k++].cost=w;
            }
        }
      printf("%d\n",kruskal());
    }
    return 0;
}
