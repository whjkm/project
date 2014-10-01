/*#include <cstdio>
#include <cstring>
int a[64];
int main()
{
    int n,sum,m,max;
    while(scanf("%d",&n)&&n)
    {
        sum=0;
        max=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            if(a[i]>max)
                max=a[i];
        }
        for(m=max;;m++)
        {
            if(sum%m==0 && m>max)
            {
              printf("%d\n",m);
              break;
            }
        }
    }
    return 0;
}
*/

#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
bool visit[100];
int stick[100],n;
bool cmp(int a,int b)
{
    return a>b;
}
int dfs(int len,int ans,int ret)
{
    if(ans==n && ret==0)
      return len;
    if(ret==0)
        ret=len;
    for(int i=0;i<n;i++)
    {
        if(visit[i])
            continue;
        if(stick[i]>len)
            continue;
        visit[i]=1;
        if(dfs(len,ans+1,ret-stick[i]))
            return len;
        visit[i]=0;
        if(ret==stick[i] && len==ret )
            break;
        while(stick[i]==stick[i+1])
            i++;
    }
    return 0;
}
int main()
{
    int sum,i,initlen;
    while(scanf("%d",&n)&&n)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
          scanf("%d",&stick[i]);
          sum+=stick[i];
        }
        sort(stick,stick+n,cmp);
        for(i=stick[0];i<sum;i++)
        {
            if(sum%i!=0)
                continue;
            for(int j=0; j<n; j++)
                visit[j]=0;
            initlen=dfs(i,0,i);
            if(initlen!=0)
                break;
        }
        printf("%d\n",initlen);
    }
    return 0;
}
