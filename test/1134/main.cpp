#include <cstdio>
#include <cstring>
#define min(x,y) x>y?y:x
using namespace std;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
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
int c,d,m;
void dfs(int a,int b,int ans)
{
    int x,y;
    if(a==c&&b==d)
    {
        m=min(m,ans);
        return ;
    }
    map[a][b]=1;
    for(int i=0;i<4;i++)
    {
        x=a+dir[i][0];
        y=b+dir[i][1];
        if(map[x][y]==0)
        {
            dfs(x,y,ans+1);
            map[x][y]=0;
        }
    }
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    while(n--)
    {
        m=9999;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        dfs(a,b,0);
        map[a][b]=0;
        printf("%d\n",m);
    }
    return 0;
}
