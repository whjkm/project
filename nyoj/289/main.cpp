/*#include <stdio.h>
int main()
{
  int n,v,c,w,i,j;
  while(scanf("%d%d",&n,&v)&&n!=0&&v!=0)
  {
     int price[1000]={0};
     for(i=0;i<n;i++)
      {
          scanf("%d%d",&c,&w);
          for(j=v;j>=c;j--)
              if(price[j]<price[j-c]+w)
                  price[j]=price[j-c]+w;
      }
      printf("%d\n",price[v]);
  }
    return 0;
}
*/

#include<stdio.h>
#include<string.h>
#define max(a,b)(a>b?a:b)
int price[1000][1000]={0},c[1000]={0},w[1000]={0};
int pack(int n,int v)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=v;j++)
    {
        if(j>=c[i])
            price[i][j]=max(price[i-1][j],price[i-1][j-c[i]]+w[i]);
        else
            price[i][j]=price[i-1][j];
    }
    return price [n][v];
}
int main()
{
    int n,v,i,p;
    while(scanf("%d%d",&n,&v)&&n!=0&&v!=0)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d",&c[i],&w[i]);
            memset(price,0,sizeof(price));
            p=pack(n,v);
            printf("%d\n",p);
    }
    return 0;
}
