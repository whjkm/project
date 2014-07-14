/*#include<stdio.h>
int map[7][7],count,n,m;
int move[4][2]={0,1,0,-1,1,0,-1,0};
void dfs(int x,int y)
{
       int i;
       if(map[x][y]==0&&x>=1&&x<=n&&y>=1&&y<=m)
       {
         if(x==n&&y==m)
             count++;
         else
         {
             for(i=0;i<4;i++)
              {
               x=x+move[i][0];
               y=y+move[i][1];
                 map[x][y]=1;
                 dfs(x,y);
                 map[x][y]=0;
              }
         }
       }
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
       count=0;
       scanf("%d%d",&n,&m);
       for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scanf("%d",&map[i][j]);
         for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
             dfs(1,1);
       printf("%d\n",count);
    }
}*/
#include<stdio.h>
int map[7][7],count,n,m;
void dfs(int x,int y)
{
    if(map[x][y]==0&&x>=1&&x<=n&&y>=1&&y<=m)
    {
        if(x==n&&y==m)
            count++;
        else
        {
          map[x][y]=1;
          dfs(x,y+1);
          dfs(x+1,y);
          dfs(x,y-1);
          dfs(x-1,y);
          map[x][y]=0;
        }
    }
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
       count=0;
       scanf("%d%d",&n,&m);
       for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scanf("%d",&map[i][j]);
       dfs(1,1);
       printf("%d\n",count);
    }
}

