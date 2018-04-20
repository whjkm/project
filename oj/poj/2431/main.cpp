#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=10001;
typedef struct node
{
    int dis,fuel;
}node;
node stop[maxn];
bool cmp(node x,node y)
{
   return x.dis>y.dis;
}
int main()
{
    int n,l,p;
    int ans=0,j=0,temp;
    while(scanf("%d",&n)!=EOF)
    {
    priority_queue<int>q;
    for(int i=0;i<n;i++)
        scanf("%d %d",&stop[i].dis,&stop[i].fuel);
    scanf("%d %d",&l,&p);
    sort(stop,stop+n,cmp);
    q.push(p);
    while(l>0 && !q.empty())
    {
        ans++;
        temp=q.top();
        q.pop();
        l-=temp;
        while(j<n && l<=stop[j].dis)
            q.push(stop[j++].fuel);
    }
    printf("%d\n",l<=0?ans-1:-1);
    }
    return 0;
}
