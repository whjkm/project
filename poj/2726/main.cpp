/*#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10001;
struct edge
{
    int dis,cost;
}map[maxn];
bool cmp(edge x,edge y)
{
    if(x.dis == y.dis){
		return x.cost < y.cost;
	}
	return x.dis < y.dis;
}
int main()
{
    int n,i,ans,count;
    while(scanf("%d",&n)&&n)
    {
        ans=maxn;
        count=0;
        for(i=0;i<n;i++)
            scanf("%d%d",&map[i].dis,&map[i].cost);
        sort(map,map+n,cmp);
        for(i=0;i<n;i++)
        {
            if(map[i].cost<ans)
            {
                count++;
                ans=map[i].cost;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
*/

/*#include <cstdio>
#include <cstring>
const int maxn=10001;
int map[maxn];
int main()
{
    int n,i,dis,cost,len,j,count,min;
    while(scanf("%d",&n)&&n)
    {
        len=0;
        count=1;
        for(i=0;i<maxn;i++)
            map[i]=maxn;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&dis,&cost);
            if(map[dis]>cost) map[dis]=cost;
            if(len<dis) len=dis;
        }
        i=0;
        while(map[i]==maxn) i++;
        min=map[i];
        for(j=i+1;j<=len;j++)
        {
            if(map[j]<min)
            {
                count++;
                min=map[j];
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn=10001;
struct edge
{
    int dis,cost;
}map[maxn];
bool cmp(edge x,edge y)
{
    if(x.dis == y.dis){
		return x.cost < y.cost;
	}
	return x.dis < y.dis;
}
int main()
{
    int n,i;
    while(scanf("%d",&n)&&n)
    {
        stack<edge>s;
        for(i=0;i<n;i++)
            scanf("%d%d",&map[i].dis,&map[i].cost);
        sort(map,map+n,cmp);
        s.push(map[0]);
        for(i=1;i<n;i++)
        {
           if(s.size()&& map[i].cost<s.top().cost)
               s.push(map[i]);
        }
        printf("%d\n",s.size());
    }
    return 0;
}
