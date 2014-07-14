#include <stdio.h>
#include <string.h>
int map[102][102];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int m,n;
void dfs(int x,int y)
{
    int tx,ty,i;
    for(i=0;i<4;i++)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(map[tx][ty]==1)
        {
            map[tx][ty]=0;
            dfs(tx,ty);
        }
    }
}
int main()
{
   int t,i,j;
   scanf("%d",&t);
   while(t--)
   {
       int sum=0;
       memset(map,0,sizeof(map));
       scanf("%d%d",&m,&n);
       for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
        scanf("%d",&map[i][j]);
       for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(map[i][j]==1)
       {
           map[i][j]=0;
           dfs(i,j);
           sum++;
       }
       printf("%d\n",sum);
   }
    return 0;
}

/*#include<stdio.h>
 #include<string.h>
 #define MAXN 100
 int num[MAXN][MAXN];
 void find(int x,int y)
 {

 if(num[x][y-1]==1) {num[x][y-1]=0;find(x,y-1);};
 if(num[x-1][y]==1) {num[x-1][y]=0;find(x-1,y);};
 if(num[x+1][y]==1) {num[x+1][y]=0;find(x+1,y);};
 if(num[x][y+1]==1) {num[x][y+1]=0;find(x,y+1);};

 }
 int main()
 {
 int N,m,n,count,i,j;
 scanf("%d",&N);
 while(N--)
 {
 count=0;
 scanf("%d%d",&m,&n);
 memset(num,0,sizeof(num));
 for(i=1;i<=m;i++)
 for(j=1;j<=n;j++)
 scanf("%d",&num[i][j]);
 for(i=1;i<=m;i++)
 for(j=1;j<=n;j++)
 {
 if(num[i][j]==1)
 {
 count++;
 find(i,j);
 }
 }
 printf("%d\n",count);
 }
 return 0;
 }
 */
