/*#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
void bfs(int n)
{
   queue<__int64>q;
   q.push(1);
   while(!q.empty())
   {
       __int64 x;
       x=q.front();
       q.pop();
       if(x%n==0)
       {
           printf("%I64d\n",x);
           return ;
       }
       q.push(x*10);
       q.push(x*10+1);
   }
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        bfs(n);
    }
    return 0;
}
*/
#include <cstdio>
#include <cstring>
long long q[2000000];
void bfs(int n)
{
    int front=0;
    int rear=0;
    q[front]=1;
    rear++;
    long long temp;
    while(rear>front)
    {
        temp=q[front];
        if(temp%n==0)
        {
            break;
        }
        temp*=10;
        q[rear]=temp;
        rear++;
        q[rear]=temp+1;
        rear++;
        front++;
    }
    printf("%lld\n",temp);
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        bfs(n);
    }
    return 0;
}
