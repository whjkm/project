#include <stdio.h>
int father[1001],rank[1001],degree[1001];
int find(int x)
{
    if(x!=father[x])
        father[x]=find(father[x]);
    return father[x];
}
void Union(int x,int y)
{
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if(fx==fy)  return ;
    if(rank[fx]>rank[fy])
               father[fy]=fx;
    else
    {
        father[fx]=fy;
        if(rank[fx]==rank[fy])
             rank[fy]++;
    }
}
int main()
{
    int t,p,q,a,b,sum,count,i;
    scanf("%d",&t);
    while(t--)
    {
        sum=0,count=0;
        scanf("%d%d",&p,&q);
        for(i=0;i<p;i++)
        {
            father[i]=i;
            rank[i]=0;
            degree[i]=0;
        }
        for(i=0; i<q; i++)
          {
              scanf("%d%d",&a,&b);
              degree[a]++;
              degree[b]++;
                Union(a,b);
          }
          for(i=0;i<p;i++)
          {
              if(find(i)==i)
                sum++;
              if(degree[i]%2==1)
                count++;
          }
          if((count==0||count==2)&&sum==1)
             printf("Yes\n");
          else
              printf("No\n");
    }
    return 0;
}


