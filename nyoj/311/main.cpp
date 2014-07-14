#include <stdio.h>
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
