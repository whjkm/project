/*#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100001;
int s[maxn],a[maxn];
long long sum[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        a[n+1]=-1;
        long long ans=-1,temp;
        int top=0,l,r;
        for(int i=1;i<=n+1;i++)
        {
            while(top!=0 && a[s[top]]>a[i])
            {
                temp=a[s[top]]*(sum[i-1]-sum[s[top-1]]);
                if(ans<temp)
                {
                    ans=temp;
                    l=s[top-1]+1;
                    r=i-1;
                }
                top--;
            }
            top++;
            s[top]=i;
        }
        printf("%lld\n%d %d\n",ans,l,r);
    }
    return 0;
}
*/


#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100001;
struct S
{
    int num,id;
}s[maxn];
struct C
{
   int num,l,r;
}c[maxn];
int a[maxn];
long long sum[maxn];
int main()
{
    int n,top,i,j,l,r;
    long long ans=-1,temp;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            c[i].num=a[i];
            sum[i]=sum[i-1]+a[i];
        }
        s[0].num=-1;
        s[0].id=0;
        top=0;
        for(i=1;i<=n;i++)
        {
            for(j=top;j>=0;j--)
         {
            if(a[i]>s[j].num) break;
            else
            {
                c[s[j].id].l=i-1;
            }
         }
         s[j+1].num=a[i];
         s[j+1].id=i;
         top=j+1;
         c[i].r=s[top-1].id+1;
        }
        for(j=0;j<=top;j++)
            c[s[j].id].l=n;
        for(i=1;i<=n;i++)
        {
            temp=(sum[c[i].l]-sum[c[i].r-1])*c[i].num;
            if(ans<temp)
            {
                ans=temp;
                l=c[i].l;
                r=c[i].r;
            }
        }
       printf("%lld\n%d %d\n",ans,r,l);
    }
    return 0;
}
