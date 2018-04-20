#include<stdio.h>
#include<stdlib.h>
void dfs(int cur)
{
    int i;
    if(cur==n&&isp[A[0]+A[n-1]])
    {
        for(i=0;i<n;i++)
            printf("%d ",A[i]);
        printf("\n");
    }
    else for(i=2;i<=n;i++)
        if(!vis[i]&&isp[i+A[cur-1]])
    {
        A[cur]=i;
        vis[i]=1;
        dfs(cur+1);
        vis[i]=0;
    }
}
int main()
{

}
