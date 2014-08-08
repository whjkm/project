#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10000+1;
struct node
{
    int u,v,w;
};
node map[5*maxn];
int father[2*maxn];
int n,m,r;
bool cmp(node x,node y)
{
    return x.w>y.w;
}
void Init()//�Բ��鼯��ʼ��
{
    for(int i=0;i<n+m;i++)
        father[i]=i;
}
int find_set(int x)//��״̬ѹ���Ĳ���
{
    if(father[x]==x)
        return x;
    else
        return father[x]=find_set(father[x]);
}
/*bool union_set(int x,int y)//��������֮��ĺϲ�
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
}*/
int kruskal()
{
    int i,sum=0;
    Init();
    sort(map,map+r,cmp);
     for(i=0;i<r;i++)
   {
      /*if(union_set(map[i].u,map[i].v))//�ж��Ƿ��γɻ�·
              sum+=map[i].w;*/
     int x=find_set(map[i].u);
     int y=find_set(map[i].v);
     if(x!=y)
     {
         father[y]=x;
         sum+=map[i].w;
     }
    }
   return sum;
}
int main()
{
   int t,x,y,d;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d%d",&n,&m,&r);
       for(int i=0;i<r;i++)
       {
            scanf("%d%d%d",&x,&y,&d);
             map[i].u=x;
             map[i].v=y+n;
             map[i].w=d;
       }
       printf("%d\n",(n+m)*10000-kruskal());
   }
    return 0;
}
