#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=0x3f3f3f3f;
const int maxn=500+20;
int map[maxn][maxn],visit[maxn],low[maxn];
int v,e;
int prim()
{
   int pos,i,j,min,sum=0;
   memset(visit,0,sizeof(visit));//初始化visit数组
   visit[1]=1;//从第一个点开始
   pos=1;//标记和记录这个点
   for(i=1;i<=v;i++)
      low[i]=map[pos][i];//用low数组记录权值
   for(i=1;i<v;i++) //第一个点已经进行了，还需要进行n-1次；
   {
       min=MAX;//把min赋初值
       for(j=1;j<=v;j++)
       {
           if(visit[j]==0&&low[j]!=0&&low[j]<min)//比较权值的大小
           {
               min=low[j];
               pos=j;//记录权值最小的点，下一次从这个点开始
           }
       }
       sum+=min;//记录权值的和
       visit[pos]=1;//标记访问
       for(j=1;j<=v;j++)//访问下一个点
       {
           if(visit[j]==0&&low[j]>map[pos][j])
              low[j]=map[pos][j];
       }
   }
   return sum;
}
int main()
{
    int n,a,b,c,i,j;
    int r[maxn];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&v,&e);
        for(i=1;i<=v;i++)
          for(j=1;j<=i;j++)
            map[i][j]=map[j][i]=MAX;
        //memset(map,0,sizeof(map));
        for(i=1;i<=e;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=map[b][a]=c;
        }
        for(j=1;j<=v;j++)
            scanf("%d",&r[j]);
        sort(r+1,r+v+1);
        printf("%d\n",prim()+r[1]);
    }
    return 0;
}
