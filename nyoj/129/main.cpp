#include<stdio.h>
#include<string.h>
#define max(a,b)?a:b
#define MAXN 10001
int parent[MAXN],visit[MAXN];
int find(int x)
{
    if(x!=parent[x])
        parent[x]=find(parent[x]);
    return parent[x];
}
void Union(int x,int y)
{
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if(fx!=fy)
    {
        if(parent[fx]<parent[fy])
           {
               parent[fx]+=parent[fy];
                parent[fy]=parent[fx];
           }
        else
        {
            parent[fy]+=parent[fx];
            parent[fx]=parent[fy];
        }
    }
}
int main()
{
    int u,v,i;
    memset(parent,-1,sizeof(parent));
    memset(visit,-1,sizeof(visit));
    while(scanf("%d%d",&u,&v)!=EOF&&u!=-1&&v!=-1)
    {
        if(u==0&&v==0)
            {

            }
    }
}
