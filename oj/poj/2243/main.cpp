#include <cstdio>
#include <cstring>
const int maxn=1000;
typedef struct Queue
{
    int  x,y,count;
}Queue;
char x1,x2;
int b,d,c;
Queue que[maxn];
bool visit[10][10];
int dir[8][2]={{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};
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
            printf("To get from %c%d to %c%d takes %d knight moves.\n",x1,b,x2,d,q.count);
            break;
        }
        for(i=0;i<8;i++)
        {
            fx=q.x+dir[i][0];
            fy=q.y+dir[i][1];
            if(fx>=1 && fy >=1 && fx<= 8 && fy <=8 && !visit[fx][fy])
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
    int a;
    while(scanf("%c%d %c%d",&x1,&b,&x2,&d)!=EOF)
    {
       memset(que,0,sizeof(que));
       a=x1-'a'+1;
       c=x2-'a'+1;
       bfs(a,b);
    }
    return 0;
}

