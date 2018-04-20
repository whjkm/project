#include <stdio.h>
#include <string.h>
int map[102][102];
int dir[4][2]={1,0,-1,0,0,-1,0,1};
int m,n;
void bfs(int x,int y)
{
    int i,tx,ty;
    for(i=0;i<4;i++)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(map[tx][ty]==1)
              {
                  map[tx][ty]=0;
                  bfs(tx,ty);
              }
    }
}
int main()
{
   int t,i,j,sum;
   scanf("%d",&t);
   while(t--)
   {
       sum=0;
       memset(map,0,sizeof(map));
       scanf("%d%d",&m,&n);
       for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
       scanf("%d",&map[i][j]);
        for(i=1;i<=m;i++)
            for(j=1;i<=n;j++)
             if(map[i][j]==1)
               {
                   sum++;
                   bfs(i,j);
               }
        printf("%d\n",sum);
   }
    return 0;
}

/*#include<stdio.h>
int map[110][110];
int direction[4][2]={-1,0,0,1,1,0,0,-1};
void initmap(int x,int y)//初始化，注意要将边界定义
{
    int i,j;
    for(i=0;i<x+2;i++)
        for(j=0;j<y+2;j++)
            map[i][j]=0;
}
void dfs(int x,int y)//搜索
{
    int i;
    map[x][y]=0;
    for(i=0;i<4;i++)
    {
        if(map[x+direction[i][0]][y+direction[i][1]]==1)
            dfs(x+direction[i][0], y+direction[i][1]);
    }
}
int main()
{
    int m,x,y,i,j,num;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&x,&y);
        initmap(x,y);
        for(i=1;i<=x;i++)
            for(j=1;j<=y;j++)
                scanf("%d",&map[i][j]);
        num=0;
        for(i=1;i<=x;i++)
            for(j=1;j<=y;j++)
                if(map[i][j]==1)
                {
                    dfs(i,j);
                    num++;
                }
        printf("%d\n",num);
    }
}
*/
