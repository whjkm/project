/*#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000001;
int a[maxn],b[maxn];
long long sum;
void Merge(int begin,int mid,int end)
{
    int i=begin,j=mid+1,pos=begin;
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
        {
            b[pos++]=a[i++];
        }
        else
        {
            b[pos++]=a[j++];
            sum+=mid-i+1;
        }
    }
    while(i<=mid) b[pos++]=a[i++];
    while(j<=end) b[pos++]=a[j++];
    for(int i=begin,j=begin;i<=end;i++,j++)
        a[i]=b[j];
}
void Sort(int begin,int end)
{
    if(begin<end)
    {
        int mid=(begin+end)/2;
        Sort(begin,mid);
        Sort(mid+1,end);
        Merge(begin,mid,end);
    }
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
            Sort(1,n);
        printf("%lld\n",sum);
    }
    return 0;
}
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000005;
struct node
{
   int val,id;
}s[maxn];
int a[maxn],n;
int lowbit(int i)
{
    return i&(-i);
}
void update(int i)
{
    while(i<=n)
    {
        a[i]++;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=a[i];
        i-=lowbit(i);
    }
    return sum;
}
bool cmp(node x,node y)
{
    if(x.val!=y.val)
        return x.val<y.val;
    return x.id<y.id;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i].val);
            s[i].id=i;
            a[i]=0;
        }
        long long ans=0;
        sort(s+1,s+n+1,cmp);
        for(i=1;i<=n;i++)
        {
            update(s[i].id);
            ans+=i-sum(s[i].id);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
