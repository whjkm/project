/*#include <cstdio>
#include <cstring>
typedef struct Queue
{
    int x,y;
    int count;
}Queue;
const int maxn=1000;
int dir[8][2]={{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};
bool visit[maxn][maxn];
Queue queue[maxn];
int c,d,l;
void bfs(int x,int y)
{
    int front=0,rear=0;
    int i,fx,fy;
    queue[rear].x=x;
    queue[rear].y=y;
    queue[rear++].count=0;
    visit[x][y]=1;
    while(front<rear)
    {
        Queue q=queue[front++];
        if(q.x==c && q.y==d)
        {
            printf("%d\n",q.count);
            break;
        }
        for(i=0;i<8;i++)
        {
             fx=q.x+dir[i][0];
             fy=q.y+dir[i][1];
            if( fx>= 0 && fy>= 0 && fx <l && fy <l&& !visit[fx][fy])
            {
                visit[fx][fy]=1;
                queue[rear].x=fx;
                queue[rear].y=fy;
                queue[rear++].count=q.count+1;
            }
        }
    }
}
int main()
{
    int t;
    int a,b;
    scanf("%d",&t);
    while(t--)
    {
        memset(queue,0,sizeof(queue));
        //memset(visit,0,sizeof(visit));
        scanf("%d",&l);
        scanf("%d%d",&a,&b);
        scanf("%d%d",&c,&d);
        bfs(a,b);
    }
    return 0;
}
*/
#include <cstdio>
#include <cstring>
const int maxn=100000;
typedef struct Queue
{
    int x,y,count;
}Queue;
Queue que[maxn];
bool visit[310][310];
int dir[8][2]={{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};
int l,c,d;
void bfs(int x,int y)
{
    memset(visit,false,sizeof(visit));
    int front=0,rear=0;
    int fx,fy,i;
    que[rear].x=x;
    que[rear].y=y;
    que[rear++].count=0;
    visit[x][y]=true;
    while(front<rear)
    {
        Queue q=que[front++];
        if(q.x==c && q.y==d)
        {
            printf("%d\n",q.count);
            break;
        }
        for(i=0;i<8;i++)
        {
            fx=q.x+dir[i][0];
            fy=q.y+dir[i][1];
            if(fx>=0 && fy >=0 && fx<l && fy <l && !visit[fx][fy])
            {
                visit[fx][fy]=true;
                que[rear].x=fx;
                que[rear].y=fy;
                que[rear++].count=q.count+1;
            }
        }
    }
}
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        memset(que,0,sizeof(que));
        scanf("%d",&l);
        scanf("%d%d",&a,&b);
        scanf("%d%d",&c,&d);
        bfs(a,b);
    }
    return 0;
}
