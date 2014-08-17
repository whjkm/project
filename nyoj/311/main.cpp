/*#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
int main()
{
    int n,m,v,c,w,i,j,a[50005];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&m,&v);
        memset(a,-100,sizeof(a));a[0]=0;
        for(i=0;i<m;i++)
        {
          scanf("%d%d",&w,&c);
          for(j=w;j<=v;j++)
           a[j]=max(a[j-w]+c,a[j]);
        }
        if(a[v]<0)
         printf("NO\n");
        else printf("%d\n",a[v]);
    }
    return 0;
}
*/

#include <cstdio>
#include <cstring>
#define max(a,b) a>b?a:b
const int maxn=50001;
int dp[maxn];
int main()
{
    int n,m,v,i,j,c,w;
    scanf("%d",&n);
    while(n--)
    {
      memset(dp,-10000,sizeof(dp));
      dp[0]=0;
      scanf("%d%d",&m,&v);
      for(i=1;i<=m;i++)
      {
          scanf("%d%d",&c,&w);
          for(j=c;j<=v;j++)
                dp[j]=max(dp[j],dp[j-c]+w);
      }
      if(dp[v]<0) printf("NO\n");
       else  printf("%d\n",dp[v]);
    }
    return 0;
}
