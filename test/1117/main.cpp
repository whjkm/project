#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10500;
int q[maxn];
int main()
{
    int t,n,a,b,i,pos,count,k=1;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        memset(q,0,sizeof(q));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
           scanf("%d%d",&a,&b);
           q[a]+=b;
        }
        for(i=1;i<=maxn;i++)
        {
            q[i+1]=q[i+1]+q[i]/3;
            q[i]=q[i]%3;
            pos=i+1;
            while(q[pos]>=3)
            {
                q[pos+1]=q[pos+1]+q[pos]/3;
                q[pos]=q[pos]%3;
                pos++;
            }
            if(q[i]!=0)
             count+=q[i];
        }
        printf("Case #%d:\n%d\n",k++,count);
    }
    return 0;
}
