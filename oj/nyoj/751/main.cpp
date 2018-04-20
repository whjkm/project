#include<stdio.h>
int a[10001];
int find(int x)
{
    if(x!=a[x])
        a[x]=find(a[x]);
    return a[x];
}
int main()
{
    int n,m,i,num[100001],u[100001],v[100001],x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            a[i]=i;
        for(i=0;i<m;i++)
          scanf("%d%d",&u[i],&v[i]);
        num[m]=n;
      for(i=m-1;i>=0;i--)
      {
          x=find(u[i]);
          y=find(v[i]);
          if(x!=y)
          {
              a[x]=y;
              num[i]=num[i+1]-1;
          }
          else
          {
              num[i]=num[i+1];
          }
      }
      for(i=1;i<=m;i++)
        printf("%d\n",num[i]);
    }
}
