/*#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100001;
int n,a[maxn],dp[maxn],Max;
void LICS()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(a[i]>a[j] && dp[i]<1+dp[j])
              dp[i]=1+dp[j];
    }
   Max=0;
   for(int i=0;i<n;i++)
        if(Max<dp[i])
          Max=dp[i];
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        LICS();
        printf("%d\n",Max);
    }
    return 0;
}
*/
#include <cstdio>
#include <cstring>
const int maxn=100001;
int dp[maxn],a[maxn];
int Binary_search(int len,int k)
{
    int start,end,mid;
    start=1;
    end=len;
    while(start<=end)
    {
        mid=(start+end)>>1;
        if(k==dp[mid])
            return mid;
        if(k>dp[mid])
            start=mid+1;
        else
            end=mid-1;
    }
    return start;
}
int main()
{
    int n,i,t,len;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
         len=1;
         dp[1]=a[0];
         for(i=1;i<n;i++)
         {
             t=Binary_search(len,a[i]);
             dp[t]=a[i];
             if(t>len)
                len=t;
         }
         printf("%d\n",len);
    }
}
