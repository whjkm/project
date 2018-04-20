#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1001;
int a[maxn],b[maxn],dp[maxn];
int n,m;
int LICS()
{
    int MAX,i,j;
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
    {
        MAX=0;
        for(j=0;j<m;j++)
           {
           if(a[i]>b[j] && MAX<dp[j])
               MAX=dp[j];
           if(a[i]==b[j])
               dp[j]=MAX+1;
           }
    }
    MAX=0;
    for(i=0;i<m;i++)
        if(dp[i]>MAX)
         MAX=dp[i];
    return MAX;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
          scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        printf("%d\n",LICS());
    }
    return 0;
}
