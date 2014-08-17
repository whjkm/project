#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=505;
const int Max=0x3f3f3f3f;
int map[maxn][maxn],low[maxn],visit[maxn];
int n,m,k;
void prim()
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
        if(mst>=Max)
			break;
        visit[pos]=j;
        for(j=1;j<=n;j++)
        {
            if(!visit[j] && low[j]>map[pos][j])
                low[j]=map[pos][j];
        }
    }
    if(mst>=Max)
        printf("-1\n");
    else
        printf("%d\n",mst);
}
int main()
{
    int t,i,j,x;
    int p,q,c;
    int a[101];
    scanf("%d",&t);
    while(t--)
    {
        memset(map,Max,sizeof(map));
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&p,&q,&c);
            if(map[p][q]>c)
            map[p][q]=map[q][p]=c;
        }
        while(k--)
		{
			scanf("%d",&x);
			for(i=1;i<=x;i++)
				scanf("%d",&a[i]);
			for(i=1;i<=x;i++)
				for(j=1;j<=x;j++)
					map[a[i]][a[j]]=0;
		}
       prim();
    }
    return 0;
}
