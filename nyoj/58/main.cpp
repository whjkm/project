/*#include <stdio.h>
#include <string.h>
int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int map[9][9]={
{1,1,1,1,1,1,1,1,1},
{1,0,0,1,0,0,1,0,1},
{1,0,0,1,1,0,0,0,1},
{1,0,1,0,1,1,0,1,1},
{1,0,0,0,0,1,0,0,1},
{1,1,0,1,0,1,0,0,1},
{1,1,0,1,0,1,0,0,1},
{1,1,0,1,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1},
};
void dfs(int a,int b,int c,int d,int now,int &mins)
{
    int i,x,y;
    if(a==c&&b==d)
    {
		if(mins>now)
			mins=now;
			return ;
    }
    map[a][b]=1;
    for(i=0;i<4;i++)
    {
        x=a+move[i][0];
        y=b+move[i][1];
        if(map[x][y]==0&&now+1<mins)
          {
            dfs(x,y,c,d,now+1,mins);
            map[x][y]=0;
          }
    }
}
int main()
{
   int n,a,b,c,d;
   scanf("%d",&n);
   while(n--)
   {
       int mins=30,now=0;
       scanf("%d%d%d%d",&a,&b,&c,&d);
       dfs(a,b,c,d,now,mins);
       map[a][b]=0;
       printf("%d\n",mins);
   }
    return 0;
}
*/

#include<stdio.h>
int map[9][9]={
{1,1,1,1,1,1,1,1,1},
{1,0,0,1,0,0,1,0,1},
{1,0,0,1,1,0,0,0,1},
{1,0,1,0,1,1,0,1,1},
{1,0,0,0,0,1,0,0,1},
{1,1,0,1,0,1,0,0,1},
{1,1,0,1,0,1,0,0,1},
{1,1,0,1,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1},
};
int a,b,c,d,min;
void dfs(int x,int y,int now)
{
    if(map[x][y])
        return ;
    if(x==c&&y==d)
    {
        if(min>now)
            min=now;
        return ;
    }
    now++;
    map[x][y]=1;
    dfs(x+1,y,now);
    dfs(x,y+1,now);
    dfs(x-1,y,now);
    dfs(x,y-1,now);
    map[x][y]=0;
}
int main()
{
    int n,now;
    scanf("%d",&n);
    while(n--)
    {
        min=9999,now=0;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        dfs(a,b,now);
        printf("%d\n",min);
    }
    return 0;
}

