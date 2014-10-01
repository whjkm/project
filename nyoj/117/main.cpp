#include <cstdio>
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
