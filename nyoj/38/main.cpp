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
   memset(visit,0,sizeof(visit));//��ʼ��visit����
   visit[1]=1;//�ӵ�һ���㿪ʼ
   pos=1;//��Ǻͼ�¼�����
   for(i=1;i<=v;i++)
      low[i]=map[pos][i];//��low�����¼Ȩֵ
   for(i=1;i<v;i++) //��һ�����Ѿ������ˣ�����Ҫ����n-1�Σ�
   {
       min=MAX;//��min����ֵ
       for(j=1;j<=v;j++)
       {
           if(visit[j]==0&&low[j]!=0&&low[j]<min)//�Ƚ�Ȩֵ�Ĵ�С
           {
               min=low[j];
               pos=j;//��¼Ȩֵ��С�ĵ㣬��һ�δ�����㿪ʼ
           }
       }
       sum+=min;//��¼Ȩֵ�ĺ�
       visit[pos]=1;//��Ƿ���
       for(j=1;j<=v;j++)//������һ����
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
