/*#include <cstdio>
#include <cstring>
const int maxn=200030;
typedef struct Queue
{
    int count,step;
}Queue;
Queue queue[maxn];
int visit[maxn];
void bfs(int n,int k)
{
    int front=0,rear=0;
    queue[rear].step=n;
    queue[rear++].count=0;
    visit[n]=1;
    while(front<rear)
    {
        Queue q=queue[front++];
        if(q.step==k)
        {
            printf("%d\n",q.count);
            break;
        }
        if(q.step-1>=0 && !visit[q.step-1])
        {
            visit[q.step]=1;
            queue[rear].step=q.step-1;;
            queue[rear++].count=q.count+1;
        }
        if(q.step<=k && !visit[q.step+1])
        {
            visit[q.step+1]=1;
            queue[rear].step=q.step+1;
            queue[rear++].count=q.count+1;
        }
        if(q.step<=k && !visit[q.step*2])
        {
            visit[q.step*2]=1;
            queue[rear].step=q.step*2;
            queue[rear++].count=q.count+1;
        }
    }
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(visit,0,sizeof(visit));
        bfs(n,k);
    }
    return 0;
}
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=200030;
queue<int>q;
int Count[maxn];
bool visit[maxn];
void bfs(int n,int k)
{
   q.push(n);
   visit[n]=1;
   Count[n]=0;
   while(!q.empty())
   {
       int x=q.front();
       q.pop();
       if(x==k)
       {
           printf("%d\n",Count[x]);
           break;
       }
       if(x-1>=0 && !visit[x-1])
       {
           q.push(x-1);
           visit[x-1]=1;
           Count[x-1]=Count[x]+1;
       }
       if(x<=k && !visit[x+1])
       {
           q.push(x+1);
           visit[x+1]=1;
           Count[x+1]=Count[x]+1;
       }
        if(x<=k && !visit[2*x])
       {
           q.push(x*2);
           visit[x*2]=1;
           Count[x*2]=Count[x]+1;
       }
   }
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(visit,0,sizeof(visit));
        bfs(n,k);
    }
    return 0;
}
