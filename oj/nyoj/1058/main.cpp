#include <cstdio>
#include <cstring>
using namespace std;
int a[30],n,k,sum;
bool visit[30],flag;
void dfs(int pos)
{
    if(flag==true)
        return ;
    if(sum>=k)
    {
        if(sum==k)
        {
            flag=true;
            printf("YES\n");
           for(int i=0;i<n;i++)
            if(visit[i])
             printf("%d ",a[i]);
        }
     return;
    }
    for(int i=pos;i<n;i++)
    {
        sum+=a[i];
        visit[i]=1;
        dfs(i+1);
        sum-=a[i];
        visit[i]=0;
    }
}
int main()
{
    int i;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        memset(visit,0,sizeof(visit));
        flag=false;
        dfs(0);
        if(!flag)
            printf("NO\n");
    }
    return 0;
}
