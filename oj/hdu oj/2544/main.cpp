#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=101;
const int Max=0x3f3f3f3f;
int map[maxn][maxn],low[maxn],visit[maxn],n;
void dijkstral()
{
   int i,j,min,pos;
   memset(visit,0,sizeof(visit));
   pos=1;
   for(i=1;i<=n;i++)
   {
       low[i]=map[pos][i];
   }
   low[1]=0;
   visit[1]=1;
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
       visit[pos]=1;
       for(j=1;j<=n;j++)
       {
           if(low[j]>min+map[pos][j])
            low[j]=min+map[pos][j];
       }
   }
}
int main()
{
    int m;
    int a,b,c;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(map,Max,sizeof(map));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(map[a][b]>c)
            {
                map[a][b]=map[b][a]=c;
            }
        }
        dijkstral();
        int temp=Max;
        temp=temp>low[n]?low[n]:temp;
        printf("%d\n",temp);
    }
    return 0;
}
