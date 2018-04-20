#include <stdio.h>
#include <string.h>
char map[100][100];
int move[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
int n,m;
void dfs(int x,int y)
{
    map[x][y]='*';
    for(int i=0;i<8;i++)
    {
        int dx=x+move[i][0];
        int dy=y+move[i][1];
        if(dx>=0&&dx<n&&dy>=0&&dy<m&&map[dx][dy]=='@')
            dfs(dx,dy);
    }
}
int main()
{
   while(scanf("%d%d",&n,&m)&&m!=0&&n!=0)
   {
       int sum=0;
       for(int i=0;i<n;i++)
          scanf("%s",map[i]);
       for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
       {
           if(map[i][j]=='@')
            {
                dfs(i,j);
                sum++;
            }
       }
       printf("%d\n",sum);
   }
    return 0;
}
