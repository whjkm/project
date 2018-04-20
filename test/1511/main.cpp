/*#include<cstdio>
#include<cstring>
struct Queue
{
    int x,y,count;
};
struct Queue Q[1000];
int visit[9][9];
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,-1},{1,1},{-1,1},{-1,-1}};
int c2,c3,r2,r3;
int bfs(int x,int y)
{
    int front=0,rear=0;
    struct Queue que;
    int fx,fy;
    Q[rear].x=x;
    Q[rear].y=y;
    Q[rear++].count=0;
    visit[x][y]=1;
    while(front<rear)
    {
        que=Q[front++];
        if(que.x==r2 && que.y==c2)
        {
             return que.count;
        }
        for(int i=0; i<8; i++)
        {
            fx=que.x+dir[i][0];
            fy=que.y+dir[i][1];
            if(fx>0&&fy>0&&fx<=8&&fy<=8 && !visit[fx][fy] &&(fx!=r3 || fy!=c3))
            {
                visit[fx][fy]=1;//标记访问
                Q[rear].x=fx;//入队
                Q[rear].y=fy;
                Q[rear++].count=que.count+1;
            }
        }
    }
}
int main()
{
    int c1,r1,sum,k=1;
    while(scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3)!=EOF)
    {
        memset(visit,0,sizeof(visit));
        sum=bfs(r1,c1);
        printf("Case %d: %d\n",k++,sum);
    }
    return 0;
}
*/
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct node
{
    int x,y,count;
};
queue<node>q;
int visit[10][10];
int dir[8][2]= {{1,0},{-1,0},{0,1},{0,-1},{1,-1},{1,1},{-1,1},{-1,-1}};
int c2,c3,r2,r3;
int bfs(int x,int y)
{
    node front,rear;
    int dx,dy;
    front.x=x;
    front.y=y;
    front.count=0;
    visit[x][y]=1;
    q.push(front);
    while(!q.empty())
    {
        front=q.front();
        q.pop();
        if(front.x==r2 && front.y==c2)
        {
            return front.count;
        }
        for(int i=0;i<8;i++)
        {
            dx=front.x+dir[i][0];
            dy=front.y+dir[i][1];
            if(dx>0&&dy>0&&dx<=8&&dy<=8 && !visit[dx][dy] && (dx!=r3 || dy!=c3))
            {
                visit[dx][dy]=1;//标记访问
                rear.x=dx;
                rear.y=dy;
                rear.count=front.count+1;
                q.push(rear);
            }
        }
    }
}
int main()
{
    int c1,r1,sum,k=1;
    while(scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3)!=EOF)
    {
        memset(visit,0,sizeof(visit));
        sum=bfs(r1,c1);
        printf("Case %d: %d\n",k++,sum);
    }
    return 0;
}

