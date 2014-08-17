/*#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int cmp(int n,int m)
{
    int a=0,b=0;
    while(n!=0)
    {
        a=a*10+n%10;
        n/=10;
    }
    while(m!=0)
    {
        b=b*10+m%10;
        m/=10;
    }
    return a<b?1:0;
}
int main()
{
   int t,i,j,s[52],a,b;
   freopen("1.txt","r",stdin);
   freopen("2.txt","w",stdout);
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&a,&b);
       for(i=a,j=0;i<=b;i++)
            s[j++]=i;
      sort(s,s+(b-a)+1,cmp);
      printf("%d",s[0]);
      for(i=1;i<j;i++)
        printf(" %d",s[i]);
      printf("\n");
   }
    return 0;
}
*/
/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=100000;
int vis[maxn+10];
int n,k;
struct node{
    int x,c;
};
int BFS(){
    queue<node> q;
    while(!q.empty())
        q.pop();
    memset(vis,0,sizeof(vis));
    node cur,next;
    cur.x=n,cur.c=0;
    vis[cur.x]=1;
    q.push(cur);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(i==0)
                next.x=cur.x-1;
            else if(i==1)
                next.x=cur.x+1;
            else
                next.x=cur.x*2;
            next.c=cur.c+1;
            if(next.x==k)
                return next.c;
            if(next.x>=0 && next.x<=maxn && !vis[next.x]){
                vis[next.x]=1;
                q.push(next);
            }
        }
    }
    return 0;
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        if(n>=k){
            printf("%d\n",n-k);
            continue;
        }
        printf("%d\n",BFS());
    }
    return 0;
}
*/
//Memory Time
//15688K 344MS

#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int father[550], m, k;
double d[550];
struct post
{
    double x, y;
}p[550];
struct edge
{
    int u, v;
    double w;
}e[500005];
bool comp(edge e1, edge e2)
{
    return  e1.w < e2.w;
}
double get_dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void Init(int n)
{
    for(int i = 1; i <= n; i++)
        father[i] = i;
}
int Find(int x)
{
    if(x != father[x])
        father[x] = Find(father[x]);
    return father[x];
}
void Merge(int a, int b)
{
    int p = Find(a);
    int q = Find(b);
    if(p > q)
        father[p] = q;
    else
        father[q] = p;
}
void Kruskal(int n)
{
    k = 0;
    double Max = 0;
    for(int i = 0; i < m; i++)
        if(Find(e[i].u) != Find(e[i].v))
        {
            Merge(e[i].u, e[i].v);
            d[k++] = e[i].w;
            n--;
            if(n == 1)
                return;
        }
}
int main()
{

    int t, S, P, i, j;
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    double x, y;
    scanf("%d",&t);
    while(t--)
    {
        m = 0;
        scanf("%d%d",&S,&P);
        Init(P);
        for(i = 1; i <= P; i++)
            scanf("%lf%lf",&p[i].x, &p[i].y);
        for(i = 1; i <= P; i++)
            for(j = i + 1; j <= P; j++)
            {
                e[m].u = i;
                e[m].v = j;
                e[m++].w = get_dis(p[i].x, p[i].y, p[j].x, p[j].y);
                e[m].u = j;
                e[m].v = i;
                e[m++].w = get_dis(p[i].x, p[i].y, p[j].x, p[j].y);
            }
        sort(e, e+m, comp);
        Kruskal(P);
        printf("%.2lf\n",d[P-S-1]);
    }
    return 0;
}
