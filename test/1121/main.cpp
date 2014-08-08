#include <cstdio>
#include <cstring>
const int maxn=30000+20;
int a[maxn];
int find(int x)
{
    if(a[x]==-1) return x;
    a[x]=find(a[x]);
    return a[x];
}
int main()
{
    int n,m,k;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=0;i<n;i++)

        for(int i=0;i<m;i++)
          {
             scanf("%d",&k);
             for(int j=0;j<k;k--)
                scanf("%d",)
          }
    }
    return 0;
}

/*#include <cstdio>
#include <cstring>
const int maxn=5000+20;
int a[maxn];
int find(int x)
{
    if(a[x]==-1) return x;
    a[x]=find(a[x]);
    return a[x];
}
void unite(int x,int y)
{
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if(fx!=fy)
        a[fx]=fy;
}
int main()
{
    int n,m,p,x,y;
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=n;i++)
        a[i]=-1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        unite(x,y);
    }
    for(int i=1;i<=p;i++)
    {
        scanf("%d%d",&x,&y);
        if((x=find(x))==(y=find(y)))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
*/
