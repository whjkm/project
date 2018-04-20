#include <stdio.h>
#include <string.h>
#define MAXN 40
int A[MAXN];
int vis[MAXN];
int n;
int isprime[40]={
0,0,1,1,0,1,0,1,0,0,
0,1,0,1,0,0,0,1,0,1,
0,0,0,1,0,0,0,0,0,1,
0,1,0,0,0,0,0,1,0,0,
};
void dfs(int cur)
{
    int i;
    if(cur==n && isprime[A[0]+A[n-1]])
    {
        for(i=0;i<n;i++)
            printf("%d ",A[i]);
        printf("\n");
    }
    else for(i=2;i<=n;i++)
    if(!vis[i] && isprime[i+A[cur-1]])
    {
        A[cur]=i;
        vis[i]=1;
        dfs(cur+1);
        vis[i]=0;
    }
}
int main()
{
   int i,j;
   int k=1;
   while(scanf("%d",&n)&&n!=0)
   {
       memset(vis,0,sizeof(vis));
       
       for(i=0;i<n;i++)
         A[i]=i+1; 
       /*for(i=0;i<=MAXN;i++)
       {
       	   A[i]=i+1;
       	   isprime[0]=isprime[1]=1;
           if(isprime[i]==0)
            for(j=i+i;j<MAXN ;j+=i)
              isprime[j]=1;
       }*/
       printf("Case %d:\n",k++);
       if(n==1)
       {
           printf("1\n");
           continue;
       }
       if(n%2!=0)
       {
           printf("No Answer\n");
           continue;
       }
	    dfs(1);
   }
    return 0;
}
